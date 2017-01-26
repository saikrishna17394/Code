#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1008
#define inf 999999999
#define lim 1000001
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli ex_gcd(lli a,lli b,lli& x,lli& y) {
	
	lli s,t,r,old_s,old_r,old_t,temp;

	s=0;old_s=1;
	t=1;old_t=0;
	r=b;old_r=a;

	while(r>0) {
		lli q=old_r/r;

		temp=r;
		r=old_r-q*r;
		old_r=temp;

		temp=s;
		s=old_s-q*s;
		old_s=temp;

		temp=t;
		t=old_t-q*t;
		old_t=temp;
	}

	x=old_s;
	y=old_t;

	return old_r;
}

// return x such that
// ax = 1 mod p
lli inv(lli a,lli p) {
	lli x,y;
	// no inverse exists because
	// 'a' and 'p' are not co-prime
	if(ex_gcd(a,p,x,y)!=1)
		return -1;
	// The below steps are necessary
	x%=p;
	if(x<0)
		x+=p;
	return x;
}

lli power(lli n,lli k,lli m) {
	lli ret=1%m;
	n%=m;
	// cout<<n<<" w "<<k<<" "<<m<<" :";
	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%m;
		n=(n*n)%m;
		k/=2;
	}
	// cout<<ret<<endl;
	return ret;
}

lli t,n,m,q;
lli A[lim];
lli B[lim]={0};

int main() {
	for(lli i=2;i<=(lli)1000;i++) {
		if(B[i]==0) {
			for(lli j=i*i;j<(lli)lim;j+=i)
				B[j]=i;
		}
	}

	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(q);

		A[0]=1%m;
		map<lli,lli> cnt;

		lli ans=1%m;

		for(lli i=1;i<=n/2;i++) {
			lli num=n-i+1;
			while(num>1) {
				// cout<<num<<"whttt"<<B[num]<<endl;
				lli val=B[num],idx=0;
				if(B[num]==0) {
					idx++;
					val=num;
					num=1;
				}
				else {
					while(num%val==0) {
						idx++;
						num/=val;
					}
				}
			
				if(m%val!=0) {
					ans=(ans*power(val,idx*(n-i+1),m))%m;
				}
				else
					cnt[val]+=idx*(n-i+1);
			}

			num=i;

			while(num>1) {
				lli val=B[num],idx=0;
				if(B[num]==0) {
					idx++;
					val=num;
					num=1;
				}
				else {
					while(num%val==0) {
						idx++;
						num/=val;
					}
				}
				lli g=inv(val,m);
				if(m%val!=0)
					ans=(ans*power(g,idx*i,m))%m;
				else
					cnt[val]-=idx*i;
			}

			A[i]=ans;
			for(map<lli,lli>::iterator it=cnt.begin();it!=cnt.end();it++) {
				A[i]=(A[i]*power(it->first,it->second,m))%m;
			}
		}
		while(q--) {
			lli x;
			inp(x);
			if(x>n/2)
				x=n-x;
			printf("%lld\n", A[x]);
		}
	}

	return 0;
}
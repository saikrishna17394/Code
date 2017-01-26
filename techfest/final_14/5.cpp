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
#define lli long long int
#define ii pair<int,int>

#define mod 1234567891
#define inf 999999999
#define lim 1000000
#define lim1 1000000000
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int A[lim]={0};
int B[lim],cnt=0;
lli fac[100],afac[100];
lli pow1(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k&1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli ncr(int n,int r) {
	lli ret=1;
	lli num=n-r+1;

	for(lli i=1;i<=r;i++) {
		ret=(ret*num)%mod;
		num++;
	}
	ret=(ret*afac[r])%mod;
	return ret;
}
lli solve(int n) {
	lli ret=1;
	int m=lim1-1;
	int num=0;
	for(int i=0;(B[i]*B[i])<=n;i++) {
		num=0;
		if(n%B[i]==0) {
			while(n%B[i]==0) {
				num++;
				n/=B[i];
			}
			ret=(ret*ncr(m+num,num))%mod;
			// ret=(ret*fac[m+num])%mod;
			// ret=(ret*afac[lim1-1])%mod;
			// ret=(ret*afac[num])%mod;
		}
	}
	if(n>1) {
		ret=(ret*ncr(m+1,1))%mod;
	}
	return ret;
}

int main() {
	fac[1]=1;
	afac[1]=1;
	for(lli i=2;i<100;i++) {
		fac[i]=(i*fac[i-1])%mod;
		afac[i]=pow1(fac[i],mod-2);
	}

	for(int i=2;i*i<lim;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=1;
		}
	}

	for(int i=2;i<lim;i++) {
		if(A[i]==0) 
			B[cnt++]=i;
	}
	// cout<<cnt<<" "<<B[cnt-1]<<endl;
	lli ans=0;

	for(int i=1;i<=lim1;i++) {
		// cout<<i<<" "<<solve(i)<<endl;
		ans=(ans+solve(i))%mod;
	}
	cout<<ans<<endl;

	return 0;
}
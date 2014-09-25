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

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

inline bool inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
	if(ch=='\n' || ch==EOF)
		return true;
	return false;
}

lli power(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k&1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}


lli t,n,B[10],fac[11];
// vector<lli> v[10];

lli A[10][101],ans,num;

int C[101];


int main() {

	fac[0]=1;

	for(lli i=1;i<11;i++)
		fac[i]=(i*fac[i-1])%mod;
	inp(t);


	while(t--) {
		inp(n);

		memset(A,0,sizeof A);
		memset(B,0,sizeof B);

		ans=1;

		for(int i=0;i<n;i++) {
			while(1) {
				bool ok=inp(num);
				A[i][num]=1;
				B[i]++;
				// cout<<i<<" "<<num<<endl;
				if(ok)
					break;
			}
			ans=(ans*B[i])%mod;
		}

		num=ans;

		// cout<<"kri "<<ans<<endl;
		for(int i=0;i<(1<<n);i++) {
			int mask=i;

			int val=0;
			lli num1=num;

			for(int k=1;k<101;k++)
				C[k]=1;

			for(int j=0;j<n;j++) {
				if(mask%2==1) {
					num1=(num1*power(B[j],mod-2))%mod;
					val++;

					for(int k=1;k<101;k++)
						C[k]&=A[j][k];
				}
				mask/=2;
			}

			if(val<=1)
				continue;

			lli num2=0;

			for(int k=1;k<101;k++)
				num2+=C[k];

			num1=(num1*num2)%mod;
			num1=(num1*fac[val-1])%mod;

			// cout<<i<<" "<<ans<<" "<<num1<<endl;
			if(val%2==0)
				ans-=num1;
			else
				ans+=num1;
			ans%=mod;
			if(ans<0)
				ans+=mod;
		}

		printf("%lld\n", ans);

	}

	return 0;
}
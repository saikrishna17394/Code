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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,A[100000],pow2[100000],B[32];

int main() {
	pow2[0]=1;

	for(int i=1;i<100000;i++)
		pow2[i]=(2*pow2[i-1])%mod;


	inp(t);

	while(t--) {
		inp(n);
		memset(B,0,sizeof B);

		for(int i=0;i<n;i++) {
			inp(A[i]);
			for(int j=0;j<32;j++) {
				if(A[i]%2==1)
					B[j]++;
				A[i]/=2;
			}
		}

		lli num=0,val=1;

		for(int j=0;j<32;j++) {
			// cout<<j<<" "<<B[j]<<" "<<num<<endl;
			if(B[j])
				num+=val;
			val*=2;
		}
		// cout<<" "<<num<<endl;

		num%=mod;
		printf("%lld\n", (num*pow2[n-1])%mod);
	}
	return 0;
}
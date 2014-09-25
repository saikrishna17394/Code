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

lli A[2][2]={{1,1},{1,0}},val[2][2],B[2][2],C[2][2];
lli ans;

void make(lli n) {
	memset(val,0,sizeof val);
	val[0][0]=1;
	val[1][1]=1;

	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			B[i][j]=A[i][j];

	while(n) {
		if(n&1) {
			for(int i=0;i<2;i++) {
				for(int j=0;j<2;j++) {
					C[i][j]=0;
					for(int k=0;k<2;k++) {
						C[i][j]+=val[i][k]*B[k][j];
						C[i][j]%=mod;
					}
				}
			}
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					val[i][j]=C[i][j];
			// cout<<n<<endl;
			// cout<<val[0][0]<<" yo "<<val[0][1]<<endl;
		}

		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				C[i][j]=0;
				for(int k=0;k<2;k++) {
					C[i][j]+=B[i][k]*B[k][j];
					C[i][j]%=mod;
				}
			}
		}
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				B[i][j]=C[i][j];

		n/=2;
	}
}

int main() {
	lli t,n;

	inp(t);

	while(t--) {
		inp(n);
		if(n<3)
			printf("%lld\n",n );
		else {
			make(n-2);
			ans=val[0][0]*2+val[0][1];
			ans%=mod;
			// cout<<val[0][0]<<" "<<val[0][1]<<endl;
			printf("%lld\n", ans);
		}
	}

	return 0;
}
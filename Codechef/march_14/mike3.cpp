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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,m,A[20][20001],a,num;
int g[20][20];
int dp[1<<20];

int main() {
	inp(n);
	inp(m);

	memset(A,0,sizeof A);
	memset(g,0,sizeof g);

	for(int i=0;i<m;i++) {
		inp(a);
		for(int j=0;j<a;j++) {
			inp(num);
			A[i][num]=1;
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=0;j<m;j++) {
			for(int k=0;k<m;k++) {
				if(A[j][i]==1 && A[k][i]==1)
					g[j][k]=1;
				// cout<<j<<" "<<k<<" "<<g[j][k]<<endl;
			}
		}
	}
	// for(int j=0;j<m;j++) {
	// 	for(int k=0;k<m;k++) {
	// 		// if(A[j][i]==1 && A[k][i]==1)
	// 		// 	g[j][k]=1;
	// 		cout<<j<<" "<<k<<" "<<g[j][k]<<endl;
	// 	}
	// }

	int ans=0;
	dp[0]=0;

	int val=1<<m;
	for(int i=1;i<val;i++) {
		int mask=i;
		dp[i]=0;
		for(int j=0;j<m;j++) {
			if(mask&1) {
				int idx=i;
				for(int k=0;k<m;k++) {
					if( (i&(1<<k))!=0   && g[j][k]==1) {
						idx^=(1<<k);
					}
				}
				// cout<<i<<" yo "<<idx<<endl;
				dp[i]=max(dp[i],1+dp[idx]);
			}
			mask>>=1;
		}
		// cout<<i<<" "<<dp[i]<<endl;
	}

	printf("%d\n", dp[val-1]);
	return 0;
}
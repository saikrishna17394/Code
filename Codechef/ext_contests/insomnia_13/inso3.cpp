#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int t,n,A[26][26];
	lli dp[10000][26],ans;
	char ch;
	
	inp(t);

	while(t--) {
		memset(A,0,sizeof A);

		for(int i=0;i<26;i++) {
			inp(n);
			while(n--) {
				cin>>ch;
				A[i][ch-'a']=1;
				// ch=x;
			}
		}

		inp(n);
		for(int i=0;i<26 && n>0;i++) {
			// cout<<n-1<<" "<<i<<
			dp[n-1][i]=1;
		}

		for(int i=n-2;i>=0;i--) {

			for(int j=0;j<26;j++) {
				dp[i][j]=0;

				for(int k=0;k<26;k++) {
					if(A[j][k]==0 && A[k][j]==0)
						dp[i][j]=(dp[i][j]+dp[i+1][k])%mod;
				}
			}
		}

		ans=0;
		for(int i=0;i<26;i++)
			ans=(ans+dp[0][i])%mod;

		if(n==0)
			printf("0\n");
		else
			printf("%lld\n",ans);
	}

	return 0;
}
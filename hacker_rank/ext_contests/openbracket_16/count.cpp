#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 200010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<double,double> ii;
typedef pair<double,int> di;

int q,n,A[lim];
int ans[51];
int dp[50][50][50][51];

int main() {
	cin >> q;

	while(q --) {
		cin >> n;
		for(int i = 0; i < n*n*n; i++)
			scanf("%d", & A[i]);

		memset(ans, 0, sizeof ans);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					int idx = i*n*n + j*n + k;
					dp[i][j][k][1] = A[idx];
					if(A[idx] == 1)
						ans[1] ++;
				}
			}
		}

		for(int d = 2; d <= n; d++) {
			for(int i = 0; i+d-1 < n; i++) {
				for(int j = 0; j+d-1 < n; j++) {
					for(int k = 0; k+d-1 < n; k++) {
						int ret = dp[i][j][k][d-1];
						ret = max(ret, dp[i+1][j][k][d-1]);
						ret = max(ret, dp[i][j+1][k][d-1]);
						ret = max(ret, dp[i+1][j+1][k][d-1]);
						ret = max(ret, dp[i][j][k+1][d-1]);
						ret = max(ret, dp[i+1][j][k+1][d-1]);
						ret = max(ret, dp[i][j+1][k+1][d-1]);
						ret = max(ret, dp[i+1][j+1][k+1][d-1]);

						dp[i][j][k][d] = ret;
						if(ret == d)
							ans[d] ++;
					}
				}
			}			
		}

		for(int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}

	return 0;
}
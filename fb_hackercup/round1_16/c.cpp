#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999

using namespace std;

int main() {
	freopen("manic_moving.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n,m,k;
	cin>>t;
	int dist[105][105];
	int dp[5005][3];
	int S[5005], D[5005];

	for(int z=1; z<=t; z++) {
		cin >> n >> m >> k;


		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = inf;
			}
		}

		while(m--) {
			int a,b,g;

			scanf("%d %d %d", &a, &b, &g);
			dist[a][b] = min(dist[a][b], g);
			dist[b][a] = min(dist[b][a], g);
		}

		for(int l = 1; l <= n; l++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j<= n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
				}
			}
		}

		int ans = 0;

		for(int i = 0; i < k; i++) {
			scanf("%d %d", &S[i], &D[i]);
			if(dist[1][S[i]] == inf || dist[1][D[i]] == inf) {
				ans = -1;
			}
		}

		if(ans == -1) {
			printf("Case #%d: %d\n", z, ans);
			continue;
		}


		dp[0][0] = dist[1][S[0]];
		dp[0][2] = dp[0][0] + dist[S[0]][D[0]];

		for(int i = 1; i < k; i++) {
			dp[i][0] = dp[i-1][2] + dist[D[i-1]][S[i]];
			dp[i][1] = dp[i-1][0] + dist[S[i-1]][S[i]];
			dp[i][2] = min(dp[i][0] + dist[S[i]][D[i]], dp[i][1] + dist[S[i]][D[i-1]] + dist[D[i-1]][D[i]]);
		}

		ans = dp[k-1][2];
		printf("Case #%d: %d\n",z, ans);

	}


	return 0;
}
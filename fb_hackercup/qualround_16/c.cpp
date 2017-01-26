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

double dp[21][21][401];


int main() {
	freopen("fighting_the_zombie.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	memset(dp, 0, sizeof dp);

	int v[] = {4,6,8,10,12,20};
	set<int> m (v, v + 6);

	for(int i = 1; i < 21; i++) {
		for(int j = 0; j < 21; j++) {
			if(m.find(j) == m.end())
				continue;

			dp[0][j][0] = 1.0;
			double val = j;
			val = 1.0/val;
			for(int k = 1; k <= j*i; k++) {

				for(int a = 1; a <= j; a++) {
					if(k < a)
						break;
					dp[i][j][k] += val * dp[i-1][j][k-a];
				}
			}

		}
	}	

	
	int t, h, s;
	cin>>t;
	double ans = 0;

	for(int a=1;a<=t;a++) {
		cin >> h >> s;

		double ans = 0;

		for(int i = 0; i < s; i++) {
			string s1;
			cin >> s1;
			int x = 0, y = 0, z = 0;

			int idx = 0;
			while(s1[idx] != 'd') {
				x = x*10 + (s1[idx] - '0');
				idx ++;
			}

			idx ++;

			while(idx < s1.length()) {
				if(s1[idx] == '+' || s1[idx] == '-') {
					for(int j = idx + 1; j < s1.length(); j++) {
						z = z*10 + (s1[j] - '0');
					}
					if(s1[idx] == '-')
						z *= -1;
					break;
				}
				y = y*10 + (s1[idx] - '0');
				idx ++;
			}

			int health = h-z;

			double pr = 0;
			for(int i = x; i <= x*y; i++) {
				if(i >= health)
					pr += dp[x][y][i];
			}

			ans = max(ans, pr);
			// cout<<x <<" " << y <<" " << z << endl;
			// printf("%d %.6f\n", health, pr);
		}
		printf("Case #%d: %.6f\n",a, ans);

	}


	return 0;
}
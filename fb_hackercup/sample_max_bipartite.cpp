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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 200;
int c[maxN][maxN], f[maxN][maxN], n;
int used[maxN];

bool dfs(int s, int t) {
	if (used[s]) {
		return false;
	}
	used[s] = true;
	if (s == t) {
		return true;
	}

	for (int i = 0; i < n; ++i) {
		if (c[s][i] - f[s][i] > 0 && dfs(i, t)) {
			++f[s][i];
			--f[i][s];
			return true;
		}
	}
	return false;
}

int flow(int s, int t) {
	memset(used, 0, sizeof(used));
	int res = 0;
	while (dfs(s, t)) {
		++res;
		memset(used, 0, sizeof(used));
	}
	return res;
}

int m, l;
string k1, k2;

bool check() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));

	int s = m + m;
	int t = m + m + 1;
	n = m + m + 2;

	for (int i = 0; i < m; ++i) {
		c[s][i] = c[m + i][t] = 1;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			bool nice = true;
			for (int k = 0; k < l; ++k) {
				if (k1[i * l + k] == '?') {
					continue;
				}
				if (k2[j * l + k] == '?') {
					continue;
				}
				if (k1[i * l + k] != k2[j * l + k]) {
					nice = false;
				}
			}
			if (nice) {
				c[i][m + j] = 1;
			}
		}
	}

	return flow(s, t) == m;
}

void solve(int test) {
	cin >> m;
	cin >> k1 >> k2;

	l = k1.size() / m;

	for (int i = 0; i < k1.size(); ++i) {
		if (k1[i] != '?') {
			if (!check()) {
				printf("Case #%d: IMPOSSIBLE\n", test);
				return ;
			}
			continue;
		}

		bool nice = false;
		for (int j = 0; j < 6; ++j) {
			k1[i] = j + 'a';
			if (check()) {
				nice = true;
				break;
			}
		}
		if (!nice) {
			printf("Case #%d: IMPOSSIBLE\n", test);
			return ;
		}
	}
	cout << "Case #" << test << ": " << k1 << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests = 0;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
	}

	return 0;
}
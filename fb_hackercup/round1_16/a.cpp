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
	freopen("pie_progress.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n,m;
	cin>>t;

	for(int a=1;a<=t;a++) {
		cin >> n >> m;

		multiset<int> s;
		int ans = 0;

		for(int i = 0; i < n; i++) {
			vector<int> v(m);
			for(int j = 0; j < m; j++) {
				cin >> v[j];
			}
			sort(v.begin(), v.end());

			for(int j = 0; j < m; j++) {
				s.insert(v[j] + 2*j + 1);
			}

			ans += *s.begin();
			s.erase(s.begin());
		}

		printf("Case #%d: %d\n",a, ans);

	}


	return 0;
}
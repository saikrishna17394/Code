#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,int> di;

int tree[lim] = {0};

void upd(int idx,int val) {
	while(idx < lim) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int solve(int idx) {
	int ret = 0;
	while(idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

vector<ii> v[lim], u[lim];
vector<int> v1[lim], v2[lim];
vector<int> u1[lim], u2[lim];

map<pair<int,ii>, int> m1,m2;
int q[lim];

int main() {
	int n;

	cin >> n;



	for(int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if(a == c) {
			v[a].push_back(ii(min(b,d),max(b,d)));

			u1[min(b,d)].push_back(a);
			u2[max(b,d)].push_back(a);

			m1[make_pair(a,ii(min(b,d),max(b,d)))] = i;
		}
		else {
			u[b].push_back(ii(min(a,c),max(a,c)));

			v1[min(a,c)].push_back(b);
			v2[max(a,c)].push_back(b);

			m2[make_pair(b,ii(min(a,c),max(a,c)))] = i;
		}
	}


	lli ans = 0;

	for(int i = 1; i < lim; i++) {

		for(int j = 0; j < v2[i].size(); j++)
			upd(v2[i][j], -1);

		for(int j = 0; j < v[i].size(); j++) {
			ii p = v[i][j];
			int val = solve(p.second - 1);
			val -= solve(p.first);
			q[m1[make_pair(i,p)]] = val;
			ans += (lli) val;
		}

		for(int j = 0; j < v1[i].size(); j++) 
			upd(v1[i][j], 1);

	}


	memset(tree, 0, sizeof tree);


	for(int i = 1; i < lim; i++) {

		for(int j = 0; j < u2[i].size(); j++)
			upd(u2[i][j], -1);

		for(int j = 0; j < u[i].size(); j++) {
			ii p = u[i][j];
			int val = solve(p.second - 1);
			val -= solve(p.first);
			q[m2[make_pair(i,p)]] = val;
		}

		for(int j = 0; j < u1[i].size(); j++)
			upd(u1[i][j], 1);
	}

	cout << ans << endl;
	for(int i = 0; i < n; i++)
		printf("%d ", q[i]);
	printf("\n");


	return 0;
}
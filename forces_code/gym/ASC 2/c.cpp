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
#define ii pair<long long int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000


using namespace std;

lli n,A[500000],ans=0;

set<ii> s;
vector<int> g[1000000];

int main() {
	freopen("huffman.in", "r", stdin);
	freopen("huffman.out", "w", stdout);

	scanf("%lld",&n);

	for(int i=0;i<n;i++) {
		scanf("%lld",&A[i]);
		s.insert(ii(A[i],i));
	}

	// n--;
	set<ii>::iterator it,it1;

	int idx=n;

	int num=n-1;
	while(num--) {
		it1=s.begin();
		it=it1;
		it++;

		lli val=it->first+it1->first;

		g[idx].push_back(it1->second);
		g[idx].push_back(it->second);

		s.erase(it);
		s.erase(it1);

		s.insert(ii(val,idx));
		idx++;
	}

	queue<pair<int,int> > q;

	q.push(make_pair(idx-1,0));

	while(!q.empty()) {
		pair<int,int> top=q.front();
		q.pop();

		if(top.first<n) {
			ans+=(A[top.first]*(lli)top.second);
		}

		for(int i=0;i<g[top.first].size();i++)
			q.push(make_pair(g[top.first][i],top.second+1));
	}

	printf("%lld\n", ans);

	return 0;
}
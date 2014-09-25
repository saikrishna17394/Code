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

int main() {
	int n,e,D[50001],a,b,cost;
	vector<ii> g[50001];
	inp(n);
	inp(e);

	while(e--) {
		inp(a);
		inp(b);
		inp(cost);
		g[a].push_back(ii(b,cost));
		g[b].push_back(ii(a,cost));
	}

	for(int i=2;i<=n;i++)
		D[i]=inf;
	
	set<ii> q;
	D[1]=0;
	q.insert(ii(0,1));

	while(!q.empty()) {
		ii top=*q.begin();

		q.erase(q.begin());

		int v=top.second,d=top.first;

		for (std::vector<ii>::iterator i = g[v].begin(); i != g[v].end(); ++i) {
			int v2=i->first;
			cost=i->second;

			if(D[v2]>max(D[v],cost)) {
				if(D[v2]!=inf)
					q.erase(q.find(ii(D[v2],v2)));
				D[v2]=max(D[v],cost);
				q.insert(ii(D[v2],v2));
			}

		}
	}

	if(D[n]==inf) 
		printf("NO PATH EXISTS\n");
	else
		printf("%d\n", D[n]);

	return 0;
}
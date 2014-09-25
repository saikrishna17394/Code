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
#define lim 100010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,m,x,y,D[100001];
vector<int> g[100001],g1[100001];

int main() {
	inp(n);
	inp(m);

	while(m--) {
		inp(x);
		inp(y);
		g[x].push_back(y);
		g1[y].push_back(x);
	}


	set<ii> s;

	for(int i=1;i<=n;i++)
		D[i]=inf;

	D[n]=0;
	s.insert(ii(0,n));

	while(!s.empty()) {

		ii top=*s.begin();

		s.erase(s.begin());

		int ver=top.second;
		int val=top.first;

		// cout<<val<<" "<<ver<<"what\n";
		if(ver==1) {
			printf("%d\n", val);
			return 0;
		}

		for(int i=0;i<g1[ver].size();i++) {
			if(D[g1[ver][i]]>val) {
				if(D[g1[ver][i]]!=inf)
					s.erase(ii(D[g1[ver][i]],g1[ver][i]));
				s.insert(ii(val,g1[ver][i]));
				D[g1[ver][i]]=val;
			}
		}

		// cout<<"man\n";
		for(int i=0;i<g[ver].size();i++) {
			if(D[g[ver][i]]>val+1) {
				if(D[g[ver][i]]!=inf)
					s.erase(ii(D[g[ver][i]],g[ver][i]));
				s.insert(ii(val+1,g[ver][i]));
				D[g[ver][i]]=val+1;
			}
		}

		// cout<<"man\n";
	}

	printf("-1\n");
	return 0;
}
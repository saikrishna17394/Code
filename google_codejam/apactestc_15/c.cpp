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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,m;
vector<int> g[9];
int A[9];
int pos[9];

int main() {
	// freopen("inp","r",stdin);
	freopen("C-small-attempt0.in", "r", stdin);	
	// freopen("A-large.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		inp(m);

		int sz=1<<n;

		for(int i=1;i<=sz;i++)
			g[i].clear();
		while(m--) {
			int e,k,b;
			cin>>e>>k>>b;
			A[e]=k;
			for(int i=0;i<b;i++) {
				int num;
				inp(num);
				g[e].push_back(num);
			}
		}
		// printf("yoo\n");
		vector<int> v;

		for(int i=1;i<=sz;i++)
			v.push_back(i-1);

		bool ok=false;
		do {

			for(int i=0;i<sz;i++) {
				pos[v[i]+1]=i;
			}
			bool ok1=true;
			for(int i=1;i<=sz;i++) {
				for(int j=0;j<g[i].size();j++) {
					int u=g[i][j];
					// i,u,A[i];
					int val=u^i;
					val|=((1<<A[i])-1);
					if(val==(sz-1)) {
						ok1=false;
						break;
					}
				}
				if(!ok1)
					break;
			}
			if(ok1) {
				ok=true;
				break;
			}
		} while(next_permutation(v.begin(),v.end()));

		if(!ok)
			printf("Case #%d: YES\n",a );
		else
			printf("Case #%d: NO\n",a );
	}


	return 0;
}
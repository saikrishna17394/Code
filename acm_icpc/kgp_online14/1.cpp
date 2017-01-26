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
int t,n,m;
vector<int> g[100001];
int B[100001],x,num;
int ans[100001];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		set<int> s;
		s.clear();

		for(int i=1;i<=m;i++) {
			B[i]=0;
			s.insert(i);
		}

		for(int i=1;i<=n;i++) {
			g[i].clear();
			inp(x);
			int num;
			for(int j=0;j<x;j++) {
				inp(num);
				g[i].push_back(num);
				// cout<<g[i][j]<<" ";
			}
			// printf("\n");
		}

		ii cur;

		cur.first=1;

		for(int i=1;i<=n;i++) {
			for(int j=0;j<g[i].size();j++) {
				B[g[i][j]]++;
				if(B[g[i][j]]==1)
					s.erase(g[i][j]);
			}
			if(s.empty()) {
				cur.second=i;
				break;
			}
		}

		printf("%d %d\n", cur.first,cur.second);


		ans[1]=cur.second;

		int l=1;

		ii sol;

		for(int i=2;i<=n;i++) {
			// cur.first=i;


			for(int j=0;j<g[i-1].size();j++) {
				B[g[i-1][j]]--;
				if(B[g[i-1][j]]==0)
					s.insert(g[i-1][j]);
			}

			while((!s.empty()) && (cur.second+1)<=n) {
				cur.second++;

				for(int j=0;j<g[cur.second].size();j++) {
					B[g[cur.second][j]]++;
					if(B[g[cur.second][j]]==1)
						s.erase(g[cur.second][j]);
				}
			}

			bool ok=false;
			if(!s.empty()) {
				// cout<<"what\n";
				cur.first=i;
				while(!s.empty()) {
					cur.first--;
					for(int j=0;j<g[cur.first].size();j++) {
						B[g[cur.first][j]]++;
						if(B[g[cur.first][j]]==1)
							s.erase(g[cur.first][j]);
					}
				}

				for(;i<=n;i++)
					printf("%d %d\n",cur.first,cur.second );
				ok=true;
				break;
			}
			if(ok)
				break;
			ans[i]=cur.second;


			if(ans[l]<i) {

				ans[l]=i;
				for(int j=l+1;j<=i;j++) {
					if(ans[j]<i)
						ans[j]=i;
					if((ans[j]-j)<(ans[l]-l))
						l=j;
				}
			}
			else {
				if((ans[i]-i)<(ans[l]-l))
					l=i;
			}
			printf("%d %d\n",l,ans[l]);
		}
	}


	return 0;
}
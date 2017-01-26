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

int t,n,m,k;
int D[510][24];
vector<pair<int,vector<int> > > g[510];

int main() {
	// freopen("inp","r",stdin);
	// freopen("A-small-attempt0.in", "r", stdin);	
	freopen("A-large.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		inp(m);
		inp(k);

		for(int i=1;i<=n;i++) {
			for(int j=0;j<24;j++)
				D[i][j]=inf;
			g[i].clear();
		}

		int x,y;
		for(int l=0;l<m;l++) {
			inp(x);
			inp(y);

			int len;

			vector<int> v;
			for(int i=0;i<24;i++) {
				inp(len);
				v.push_back(len);
			}

			g[x].push_back(make_pair(y,v));
			g[y].push_back(make_pair(x,v));
		}

		for(int j=0;j<24;j++) {
			D[1][j]=0;

			set<ii> Q;
			Q.insert(ii(0,1));


			while(!Q.empty()) {
				ii top=*Q.begin();

				Q.erase(top);

				int v=top.second,d=top.first;

				for(int i=0;i<g[v].size();i++) {

					int nbr=g[v][i].first;
					vector<int> v1=g[v][i].second;

					int val=inf;
					// cout<<d<<" "<<" \n";
					for(int b=0;b<24;b++) {
						// cout<<v1[(d+b+j)%24]<<" ";
						val=min(val,d+b+v1[(d+b+j)%24]);
					}
					// printf("\n");

					if(D[nbr][j]>val) {
						Q.erase(ii(D[nbr][j],nbr));
						D[nbr][j]=val;
						Q.insert(ii(D[nbr][j],nbr));
					}
				}

				// cout<<v<<" :\n";
				// for(int i=1;i<=n;i++)
				// 	cout<<D[i][j]<<" ";
				// cout<<endl;
			}
		}

		printf("Case #%d:",a);
		for(int l=0;l<k;l++) {
			int d,s;
			inp(d);
			inp(s);
			if(D[d][s]==inf)
				printf(" %d",-1);
			else
				printf(" %d",D[d][s]);
		}
		printf("\n");


	}


	return 0;
}
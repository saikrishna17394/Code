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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[2002][2002],D[2002],a,b,C[2002][2002],par[2002];
vector<int> g[2002];

int n,m;

int main() {
	while(scanf("%d %d",&n,&m)!=EOF) {
		memset(A,0,sizeof A);
		memset(C,-1,sizeof C);


		A[0][1]=2;
		C[0][1]=0;
		A[2*n][2*n+1]=2;
		C[2*n][2*n+1]=0;

		g[0].push_back(1);
		g[2*n].push_back(2*n+1);

		for(int i=1;i<=n;i++) {
			A[2*i-1][2*i]=1;
			g[2*i-1].push_back(2*i);
			C[2*i-1][2*i]=0;
		}
		A[1][2]=2;
		A[2*n-1][2*n]=2;
		
		while(m--) {
			inp(a);
			inp(b);
			inp(C[2*a][2*b-1]);
			g[2*a].push_back(2*b-1);
			A[2*a][2*b-1]=1;
		}

		// cout<<"man\n";
		int x=2; // because min 2 vertex disjoint paths was
				// the question
		int ans=0;

		while(x--) {
			memset(par,-1,sizeof par);
			fill(D,D+(2*n+2),inf);
			D[0]=0;

			for(int a=1;a<(2*n+2);a++) {

				for(int i=0;i<(2*n+2);i++) {
					for(int j=0;j<g[i].size();j++) {
						if(A[i][g[i][j]]>0) {
							if(D[g[i][j]] > D[i]+C[i][g[i][j]]) {
								par[g[i][j]]=i;
								D[g[i][j]]=D[i]+C[i][g[i][j]];
							}
						}
						if(A[g[i][j]][i]>0) {
							if(D[i]>D[g[i][j]]+C[g[i][j]][i]) {
								par[i]=g[i][j];
								D[i]=D[g[i][j]]+C[g[i][j]][i];
							}
						}
					}
				}
			}

			// cout<<D[1]<<" "<<par[1]<<endl;
			int ver=2*n+1;

			while(ver!=0) {
				// cout<<ver<<" w"<<par[ver]<<endl;
				ans+=C[par[ver]][ver];
				A[par[ver]][ver]--;
				C[ver][par[ver]]=(C[par[ver]][ver]*-1);
				A[ver][par[ver]]++;

				ver=par[ver];
				// cout<<ver<<" w"<<endl;
			}
		}

		printf("%d\n",ans );
	}
	return 0;
}
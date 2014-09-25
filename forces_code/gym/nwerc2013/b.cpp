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
#define lim 10000000

using namespace std;

int v,e,g[500][500]={0},A[451],ans=0;
ii B[900];

int C[3];

int main() {
	
	while(scanf("%d %d",&v,&e)!=EOF) {
		// cout<<"what\n";
		// scanf("%d %d",&v,&e);
		ans=0;
		for(int i=1;i<=v;i++)
			scanf("%d",&A[i]);
		memset(g,0,sizeof g);
		for(int i=0;i<e;i++) {
			scanf("%d %d",&B[i].first,&B[i].second);
			g[B[i].first][B[i].second]=1;
			g[B[i].second][B[i].first]=1;
		}
		
		sort(B,B+e);

		for(int i=0;i<e;i++) {
			int val=A[B[i].first]+A[B[i].second];
			ans=max(ans,val);
			for(int j=i+1;j<e;j++) {
				
				int sum=val+A[B[j].first]+A[B[j].second];

				if(B[i].first==B[j].first) {
					if(g[B[i].second][B[j].second]==1)
						ans=max(ans,val+A[B[j].second]);
				}
				else if(B[i].second==B[j].first) {
					if(g[B[i].first][B[j].second]==1)
						ans=max(ans,val+A[B[j].second]);					
				}
				else if(B[i].second==B[j].second) {
					if(g[B[i].first][B[j].first]==1)
						ans=max(ans,val+A[B[j].first]);					
				}
				else {
					if(g[B[i].first][B[j].first]==1 && g[B[i].first][B[j].second]==1) {
						if(g[B[i].second][B[j].first]==1 && g[B[i].second][B[j].second]==1) {
							ans=max(ans,sum);
						}
					}
				}

			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
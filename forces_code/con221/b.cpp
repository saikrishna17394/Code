#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

int A[101][101]={0},n,m,a,b,c;

int main() {
	cin>>n>>m;

	while(m--) {
		scanf("%d %d %d",&a,&b,&c);
		A[a][b]+=c;

		// cout<<" "<<A[a][b]<<endl;
		for(int j=1;j<=n;j++) {
			if(A[j][a]==0)
				continue;
			if(A[j][a]<A[a][b]) {
				A[a][b]-=A[j][a];
				A[j][b]+=A[j][a];
				A[j][a]=0;
				// cout<<A[a][b]<<endl;
			}
			else {
				A[j][a]-=A[a][b];
				A[j][b]+=A[a][b];
				A[a][b]=0;
			}
		}

		for(int j=1;j<=n;j++) {
			if(A[b][j]==0)
				continue;
			if(A[b][j]>A[a][b]) {
				A[b][j]-=A[a][b];
				A[a][j]+=A[a][b];
				A[a][b]=0;
			}
			else {
				A[a][b]-=A[b][j];
				A[a][j]+=A[b][j];
				A[b][j]=0;
			}
		}
	}

	int ans=0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				ans+=A[i][j];

	printf("%d\n", ans);
	return 0;
}
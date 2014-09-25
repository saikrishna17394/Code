#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int n,m,k,A[300],val,mark[301],num;

	int g[301][301];
	memset(g,0,sizeof g);
	memset(mark,0,sizeof mark);

	scanf("%d %d %d",&n,&m,&k);

	for(int i=0;i<k;i++) {
		scanf("%d",&A[i]);
		mark[A[i]]=1;
	}

	val=((n-1)*(n-2))/2;
	val+=(n-k);

	num=0;
	if(val<m) {
		printf("-1\n");
		return 0;
	}
	else {
		// cout<<num<<" "<<m<<endl;
		for(int i=1;i<=n && num<m;i++) {
			if(mark[i]==0) {
				g[A[0]][i]=1;
				g[i][A[0]]=1;
				num++;
				if(num==m)
					break;
				g[A[1]][i]=1;
				g[i][A[1]]=1;
				num++;
			}

		}
		// cout<<num<<" "<<m<<endl;
		for(int i=1;i<=n && num<m;i++) {
			if(i==A[0])
				continue;
			for(int j=i+1;j<=n && num<m;j++) {
				if(j==A[0])
					continue;
				if(g[i][j]==0) {
					g[i][j]=1;
					g[j][i]=1;
					num++;
				}
			}
		}
		// cout<<num<<" "<<m<<endl;
	}

	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(g[i][j]==1)
				printf("%d %d\n",i,j);
		}
	}

	return 0;
}
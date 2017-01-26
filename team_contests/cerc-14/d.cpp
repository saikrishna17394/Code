#include <bits/stdc++.h>
#define ii pair<int,int>
#define inf 999999999

using namespace std;

int t,n;

pair<ii,int> A[1000];
int g[1000][1000];
int ans[1000],vis[1000];

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int sq(int x) {
	return x*x;
}

bool check(int i,int j) {
	int val=A[i].second+A[j].second;
	ii p1=A[i].first,p2=A[j].first;
	
	int val2=sq(p1.first-p2.first)+sq(p1.second-p2.second);
	
	int val1=sqrt(val2);
	if(val1==val && val1*val1==val2)
		return true;
	return false;
}

void dfs(int i,int sgn) {
	vis[i]=1;
	ans[i]=sgn;
	
	for(int j=0;j<n;j++)
		if(g[i][j]==1 && vis[j]==0)
			dfs(j,sgn*-1);
}

int main() {
	cin>>t;
	memset(g,0,sizeof g);
	
	while(t--) {
		cin>>n;
		
		for(int i=0;i<n;i++)
			scanf("%d %d %d",&A[i].first.first,&A[i].first.second,&A[i].second);
		
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(check(i,j)) {
					g[i][j]=1;
					g[j][i]=1;
				}
				else {
					g[i][j]=0;
					g[j][i]=0;
				}
			}
		}
		
		memset(vis,0,sizeof vis);
		memset(ans,0,sizeof ans);
		
		dfs(0,1);
		
		for(int i=0;i<n;i++) {
			if(ans[i]==0) {
				printf("not moving\n");
			}
			else {
				int a=A[0].second;
				int b=A[i].second;
				int g=gcd(a,b);
				a/=g;
				b/=g;
				if(b==1)
					printf("%d ",a);
				else
					printf("%d/%d ",a,b);
				
				if(ans[i]>0)
					printf("clockwise\n");
				else
					printf("counterclockwise\n");
				
			}
		}
				
	}

	return 0;
}
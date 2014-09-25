#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <list>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}
int t,n,A[1001][1001],m,a,vis[1001],ind,ans;
int in_edges[1001],scc_size[1001],ver_sccind[1001],scc_ind;


stack<int> s;

void rev_dfs(int i) {
	vis[i]=1;
	for(int j=1;j<=n;j++)
		if(A[j][i]==1 && vis[j]==0)
			rev_dfs(j);
	s.push(i);
}

void dfs(int i) {
	ver_sccind[i]=scc_ind;
	scc_size[scc_ind]++;

	for(int j=1;j<=n;j++) {
		if(A[i][j]==1) {
			// cout<<i<<" "<<j<<" "<<ver_sccind[j]<<endl;
			// Ee kinds else if satement dagara jagratta sumi 
			// Okasari chuskondi dani scc component lo dani edges ne add
			// chestaru lekapote
			if(ver_sccind[j]==-1)
				dfs(j);
			else if(ver_sccind[j]!=scc_ind)
				in_edges[ver_sccind[j]]++;
			else
				;
			// cout<<i<<" "<<j<<" "<<ver_sccind[j]<<" "<<in_edges[ver_sccind[j]]<<endl;
		}
	}

}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		memset(A,0,sizeof A);

		for(int i=1;i<=n;i++) {
			inp(m);
			for(int j=0;j<m;j++) {
				inp(a);
				A[a][i]=1;
			}
		}

		memset(vis,0,sizeof vis);

		for(int i=1;i<=n;i++)
			if(vis[i]==0)
				rev_dfs(i);

		memset(in_edges,0,sizeof in_edges);
		memset(ver_sccind,-1,sizeof ver_sccind);

		scc_ind =0;	

		while(!s.empty()) {
			ind=s.top();
			s.pop();

			// cout<<" "<<ind<<endl;
			if(ver_sccind[ind]==-1) {
				in_edges[scc_ind]=0;
				scc_size[scc_ind]=0;
				dfs(ind);
				scc_ind++;
			}
			// cout<<" "<<ind<<" "<<ver_sccind[ind]<<endl;
		}

		// Now have a look at number of SCC's with zero inward edges.
		int num=0;
		for(int i=0;i<scc_ind;i++) {
			// cout<<i<<" "<<in_edges[i]<<endl;
			if(in_edges[i]==0) {
				ans=scc_size[i];
				num++;
			}
		}

		if(num==1)
			printf("%d\n", ans);
		else
			printf("0\n");
	}

	return 0;
}
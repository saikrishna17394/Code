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
#define inf 1099999999
#define lim 500010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n;
int A[lim],in[lim],dis[lim],vis[lim];

void dfs(int u) {
	vis[u]=1;
	if(A[u]==-1) {
		dis[u]=1;
		return;
	}

	if(vis[A[u]]==0) {
		dfs(A[u]);
		dis[u]=min(dis[A[u]]+1,inf);
	}
	else
		dis[u]=inf;
	
}
int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			in[i]=0;
			dis[i]=-1;
		}

		for(int i=0;i<n;i++) {
			inp(A[i]);
			if(A[i]>=0)
				in[A[i]]++;

			cout<<A[i]<<" "<<in[A[i]]<<"sdfsd"<<endl;
		}

		vector<int> v;

		for(int i=1;i<n;i++) {
			// cout<<i<<" in "<<in[A[i]]<<endl;
			if(in[i]==0) {
				if(vis[i]==0)
					dfs(i);
				if(dis[i]!=inf)
					v.push_back(dis[i]);

				cout<<i<<" a "<<dis[i]<<endl;
			}
		}

		sort(v.begin(),v.end());


		int u=0;
		int val=0;
		while(vis[u]==0) {
			vis[u]=1;
			u=A[u];
			if(u==-1) {
				val++;
				break;
			}

			if(vis[u]==0)
				val++;
		}

		cout<<u<<" sdfd "<<val<<endl;
		int ans=1;

		if(u==-1) {
			ans=max(ans,val);

			if(v.size()>0)
				ans=max(ans,val+v[v.size()-1]);
		}
		else {
			if(v.size()>0)
				ans=max(ans,val+v[v.size()-1]+1);
			else
				ans=max(ans,val+1);
		}


		printf("%d\n", ans);
	}

	return 0;
}
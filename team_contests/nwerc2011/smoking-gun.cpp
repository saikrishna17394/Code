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

int n,M,t,vis[101],C[101],B[101];
ii A[101];
vector<int> g[101],l;
map<string,int> m;
map<int,string> m1;

string s1,s2,s3,s;
int i1,i2,i3;

lli dist(int i,int j) {
	lli val=(lli)(A[i].first-A[j].first);
	val*=val;
	lli val1=(lli)(A[i].second-A[j].second);
	val1*=val1;
	return val+val1;
}

bool dfs(int i) {
	if(vis[i]==0)
		return false;

	vis[i]=0;
	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==1)
			continue;
		if(!dfs(g[i][j]))
			return false;
	}
	vis[i]=1;
	l.push_back(i);
	return true;
}

int main() {
	inp(t);

	while(t--) {
		// cout<<t<<" \n";
		inp(n);
		inp(M);

		m.clear();
		m1.clear();
		for(int i=1;i<=n;i++) {
			cin>>s;
			m[s]=i;
			m1[i]=s;
			inp(A[i].first);
			inp(A[i].second);
			g[i].clear();
		}

		memset(C,0,sizeof C);
		memset(B,0,sizeof B);

		while(M--) {
			cin>>s1;
			cin>>s2>>s2;
			cin>>s3>>s3>>s3;			
			i1=m[s1];
			i2=m[s2];
			i3=m[s3];
			if(dist(i1,i2)>=dist(i1,i3)) {
				g[i2].push_back(i3);
				// cout<<i2<<" "<<i3<<endl;
				C[i2]=1;
				C[i3]=1;
			}
			B[i2]=1;
			B[i3]=1;
		}

		bool ok=false;
		for(int i=1;i<=n;i++) {
			if(B[i]!=C[i])
				ok=true;
		}
		if(ok) {
			printf("UNKONWN\n");
			continue;
		}

		ok=false;
		memset(vis,-1,sizeof vis);
		l.clear();
		for(int i=1;i<=n;i++) {
			if(C[i]==0)
				continue;
			if(vis[i]==-1) {
				if(!dfs(i)) {
					printf("IMPOSSIBLE\n");
					ok=true;
					break;
				}
			}
		}
		if(ok)
			continue;

		ok=true;
		for(int i=l.size()-1;i>0;i--) {
			int v=l[i];
			bool ok1=false;
			for(int j=0;j<g[v].size();j++) {
				if(g[v][j]==l[i-1]) {
					ok1=true;
				}
			}
			if(!ok1) {
				ok=false;
				break;
			}
		}

		if(!ok ) {
			printf("UNKONWN\n");
			continue;
		}

		for(int i=l.size()-1;i>=0;i--)
			cout<<m1[l[i]]<<" ";
		cout<<endl;
	}

	return 0;
}
#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

int n;

vector<ii> nodes;

int g[2010][2010];
int g1[2010][2010];
int scc[2010],vis[2010];

vector<int> st;

void dfs(int u) {
	vis[u]=1;

	for(int v=0;v<nodes.size();v++) {
		if(g[u][v]==1 && vis[v]==0)
			dfs(v);
	}
	st.push_back(u);
}

int idx=0;

void dfs1(int u) {
	vis[u]=1;
	scc[u]=idx;

	for(int v=0;v<nodes.size();v++) {
		if(g1[u][v]==1 && vis[v]==0)
			dfs1(v);
	}
}

int match[2010];
vector<int> g2[2010];

bool bpm(int u) {
	for(int i=0;i<g2[u].size();i++) {
		int nxt=g2[u][i];
		if(vis[nxt]==1)
			continue;
		vis[nxt]=1;
		if(match[nxt]==-1 || bpm(match[nxt]) ) {
			match[nxt]=u;
			return true;
		}
	}
	return false;
}

int main() {
	cin>>n;


	nodes.push_back(ii(-1,-1));

	for(int i=0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		nodes.push_back(ii(i,a));
		nodes.push_back(ii(i,b));
	}

	// g is the graph where each transition in the automaton is a vertex
	// so a node (a,b) has an edge to node (b,c).
	// node(a,b) refers to the transition from a->b
	// g1 is the transpose of graph of g
	// node (-1,-1) is the start vertex which has edges to
	// both the transitions from state 0.

	memset(g,0,sizeof g);
	memset(g1,0,sizeof g1);

	g[0][1]=1;
	g[0][2]=1;
	g1[1][0]=1;
	g1[2][0]=1;

	for(int i=1;i<nodes.size();i++) {
		for(int j=1;j<nodes.size();j++) {
			if(i==j)
				continue;
			if(nodes[i].second==nodes[j].first) {
				g[i][j]=1;
				g1[j][i]=1;
			}
		}

	}

	//now we are finding the Strongly connected components
	// of graph g.

	memset(vis,0,sizeof vis);

	for(int i=0;i<nodes.size();i++) {
		if(vis[i]==0)
			dfs(i);
	}

	memset(vis,0,sizeof vis);

	for(int i=st.size()-1;i>=0;i--) {
		int cur=st[i];
		if(vis[cur]==0) {
			dfs1(cur);
			idx++;
		}
	}


	// solving a max. bipartite matching for
	// the constraints generated to find the 
	// min. number of resets.
	

	for(int i=0;i<nodes.size();i++) {
		for(int j=0;j<nodes.size();j++) {
			if(g[i][j]==1 && scc[i]!=scc[j]) {
				g2[scc[j]].push_back(scc[i]);
			}
		}
	}

	memset(match,-1,sizeof match);
	int ans=0;
	for(int i=0;i<idx;i++) {
		memset(vis,0,sizeof vis);
		if(bpm(i))
			ans++;
	}

	cout<<idx-1-ans<<endl;
	return 0;
}
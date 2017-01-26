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
#define lli long long int
#define ii pair<int,int>

#define mod 5000000
#define inf 999999999
#define lim 100001
#define LN 18
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


struct node {
	node* left,*right;
	int count;

	node(int count,node *left,node *right)
		:count(count),left(left),right(right) {}

	node *insert(int l,int r,int w);	
};

node* null=new node(0,NULL,NULL);

node* root[lim];
vector<int> g[lim];
int par[lim][LN],n,q,A[lim],B[lim],idx,depth[lim];
map<int,int> m;

void dfs(int cur,int prev) {
	par[cur][0]=prev;
	if(prev!=-1)
		depth[cur]=depth[prev]+1;

	// cout<<cur<<" "<<prev<<" : \n";
	if(prev==-1)
		root[cur]=null->insert(0,idx-1,m[A[cur]]);
	else
		root[cur]=root[prev]->insert(0,idx-1,m[A[cur]]);

	// cout<<root[cur]->count<<"-------"<<endl;

	for(int i=0;i<g[cur].size();i++)
		if(g[cur][i]!=prev)
			dfs(g[cur][i],cur);
}

int lca(int u,int v) {
	if(depth[u]<depth[v])
		return lca(v,u);

	int diff=depth[u]-depth[v];

	for(int i=0;i<LN;i++) {
		if(diff%2==1)
			u=par[u][i];
		diff/=2;
	}

	if(u!=v) {
		for(int i=LN-1;i>=0;i--) {
			if(par[u][i]!=par[v][i]) {
				u=par[u][i];
				v=par[v][i];
			}
		}
		return par[u][0];
	}
	return u;
}

int query(node* u,node* v,node* lc,node *p,int l,int r,int k) {
	if(l==r)
		return r;

	int cnt=u->left->count+v->left->count;
	cnt+=-lc->left->count-p->left->count;

	// cout<<l<<" "<<r<<" "<<cnt<<" "<<k<<endl;

	
	int mid=(l+r)/2;
	if(k>cnt)
		return query(u->right,v->right,lc->right,p->right,mid+1,r,k-cnt);

	return query(u->left,v->left,lc->left,p->left,l,mid,k);
}

int main() {
	null->left=null;
	null->right=null;

	inp(n);
	inp(q);

	for(int i=1;i<=n;i++) {
		inp(A[i]);
		m[A[i]]=1;
	}

	idx=0;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		it->second=idx;
		// cout<<it->first<<" "<<it->second<<endl;
		B[idx]=it->first;
		idx++;
	}

	int a,b;
	for(int i=1;i<n;i++) {
		inp(a);
		inp(b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	memset(par,-1,sizeof par);
	depth[1]=0;
	dfs(1,-1);

	for(int j=1;j<LN;j++) {
		for(int i=1;i<=n;i++) {
			if(par[i][j-1]!=-1)
				par[i][j]=par[par[i][j-1]][j-1];
		}
	}

	int u,v,k;
	while(q--) {
		// printf("wht\n");
		inp(u);
		inp(v);
		inp(k);

		int ans;

		int l=lca(u,v);
		int p=par[l][0];
		// cout<<u<<" "<<v<<" "<<l<<" "<<p<<" "<<k<<endl;
		if(p==-1)
			ans=query(root[u],root[v],root[l],null,0,idx-1,k);
		else
			ans=query(root[u],root[v],root[l],root[p],0,idx-1,k);

		printf("%d\n", B[ans]);
	}

	return 0;
}

node* node::insert(int l,int r,int w) {
	// cout<<l<<" "<<r<<" "<<w<< " ";
	if(l<=w && w<=r) {
		// cout<<count+1<<endl;
		if(l==r)
			return new node(count+1,NULL,NULL);

		int m=(l+r)/2;
		return new node(count+1,left->insert(l,m,w),right->insert(m+1,r,w));
	}
	// cout<<count<<endl;
	return this;
}
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
int m,n,cnt;
string words[100000];
map<string,int> dct;
pair<string,string> syn[100000];

vector<int> g[300000],g1[300000],g2[300000];
ii A[300000],ans[300000];
int vis[300000]={0},cmp[300000];
vector<int> v;

ii min1(ii a,ii b) {
	if(a.first<b.first)
		return a;
	if(a.first==b.first)
		return ii(a.first,min(a.second,b.second));
	return b;
}

void dfs(int i) {
	vis[i]=1;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0)
			dfs(g[i][j]);
	}
	v.push_back(i);

	return;
}

int num=0;

void dfs1(int i) {
	vis[i]=1;
	cmp[i]=num;

	ans[num]=min1(ans[num],A[i]);

	for(int j=0;j<g1[i].size();j++) {
		if(vis[g1[i][j]]==0)
			dfs1(g1[i][j]);
	}

	return;
}


void dfs2(int i) {
	vis[i]=1;

	for(int j=0;j<g2[i].size();j++) {
		if(vis[g2[i][j]]==0)
			dfs2(g2[i][j]);
		ans[i]=min1(ans[i],ans[g2[i][j]]);
	}

	return;
}

int main() {
	cin>>m;
	for(int i=0;i<m;i++) {
		cin>>words[i];
		for(int j=0;j<words[i].size();j++)
			if(words[i][j]>='a')
				words[i][j]-=('a'-'A');
		dct[words[i]]=1;
	}

	cin>>n;
	
	for(int i=0;i<n;i++) {
		cin>>syn[i].first>>syn[i].second;

		for(int j=0;j<syn[i].first.size();j++)
			if(syn[i].first[j]>='a')
				syn[i].first[j]-=('a'-'A');

		for(int j=0;j<syn[i].second.size();j++)
			if(syn[i].second[j]>='a')
				syn[i].second[j]-=('a'-'A');

		dct[syn[i].first]=1;
		dct[syn[i].second]=1;
	}

	int idx=0;
	for(map<string,int>::iterator it=dct.begin();it!=dct.end();it++) {
		A[idx].second=it->first.length();
		A[idx].first=0;
		for(int i=0;i<A[idx].second;i++)
			if((it->first)[i]=='R')
				A[idx].first++;
		it->second=idx++;
		// cout<<it->first<<" "<<it->second<<endl;
	}

	cnt=idx;

	for(int i=0;i<n;i++) {
		// cout<<"man "<<syn[i].first<<" "<<syn[i].second<<endl;
		// cout<<dct[syn[i].first]<<" "<<dct[syn[i].second]<<endl;
		g[dct[syn[i].first]].push_back(dct[syn[i].second]);
		g1[dct[syn[i].second]].push_back(dct[syn[i].first]);
	}

	for(int i=0;i<cnt;i++)
		if(vis[i]==0)
			dfs(i);


	num=0;
	memset(vis,0,sizeof vis);
	for(int i=v.size()-1;i>=0;i--) {
		if(vis[v[i]]==0) {
			ans[num]=A[v[i]];
			dfs1(v[i]);
			// cout<<num<<" devuda "<<ans[num].first<<" "<<ans[num].second<<endl;
			num++;
		}
	}


	for(int i=0;i<cnt;i++) {
		for(int j=0;j<g[i].size();j++)
			if(cmp[i]!=cmp[g[i][j]]) {
				// cout<<cmp[i]<<" wht "<<cmp[g[i][j]]<<endl;
				g2[cmp[i]].push_back(cmp[g[i][j]]);
			}
	}

	memset(vis,0,sizeof vis);
	for(int i=0;i<num;i++) {
		if(vis[i]==0) {
			dfs2(i);
		}
	}

	pair<lli,lli> p=pair<lli,lli>(0,0);
	for(int i=0;i<m;i++) {
		// cout<<words[i]<<" "<<dct[words[i]]<<" "<<cmp[dct[words[i]]]<<endl;
		ii p1=ans[ cmp[dct[words[i]]] ];
		p.first+=(lli)p1.first;
		p.second+=(lli)p1.second;
	}

	printf("%lld %lld\n", p.first,p.second);
	return 0;
}
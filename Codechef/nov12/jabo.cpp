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
#define ii pair<long long int,int>


using namespace std;

int n,r,c;
string s;

int conv(int l) {
	int u=0;

	for(int i=l;i<(l+2);i++) {
		u=u*52;
		if(s[i]>='A' && s[i]<='Z')
			u+=s[i]-'A';
		else
			u+=s[i]-'a'+26;
	}
	u--;
	// u/=5;

	int val=0;
	for(int i=l+2;i<(l+4);i++) {
		val=val*52;
		if(s[i]>='A' && s[i]<='Z')
			val+=s[i]-'A';
		else
			val+=s[i]-'a'+26;
	}
	val--;
	val/=5;

	return (u+c*val);
}

int par[500*2500],sz[500*2500];
int val[500*2500];

int root(int i) {
	if(par[i]==i)
		return i;
	return par[i]=root(par[i]);
}

void join(int a,int b) {
	a=root(a);
	b=root(b);

	if(a==b)
		return;
	if(sz[a]>=sz[b]) {
		sz[a]+=sz[b];
		val[a]+=val[b];
		par[b]=a;
	}
	else {
		sz[b]+=sz[a];
		val[b]+=val[a];
		par[a]=b;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin>>n>>r>>c;

	for(int i=0;i<(r*c);i++) {
		par[i]=i;
		val[i]=0;
		sz[i]=1;
	}

	int u,v;

	while(n--) {
		cin>>s;
		u=conv(1);
		if(s.length()>5)
			v=conv(5);
		
		if(s[0]=='W') {
			join(u,v);
		}
		else if(s[0]=='V') {
			u=root(u);
			val[u]++;
		}
		else if(s[0]=='R') {
			u=root(u);
			val[u]--;
		}
		else {
			u=root(u);
			v=root(v);

			if(val[u]>0 && val[v]==0)
				printf("ON\n");
			else if(val[u]==0 && val[v]>0)
				printf("ON\n");
			else
				printf("OFF\n");
		}
	}

	return 0;
}
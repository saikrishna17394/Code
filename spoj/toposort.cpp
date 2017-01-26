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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,m,a,b;
vector<int> g[10001];
int in[10001]={0};

int main() {
	inp(n);
	inp(m);

	int k=m;
	while(k--) {
		inp(a);
		inp(b);
		g[a].push_back(b);
		in[b]++;
	}

	set<int> s;
	for(int i=1;i<=n;i++)
		if(in[i]==0)
			s.insert(i);

	int val=m;
	vector<int> v;
	while(!s.empty()) {
		int ver=*s.begin();
		// cout<<ver<<endl;
		s.erase(ver);
		v.push_back(ver);
		for(int j=0;j<g[ver].size();j++) {
			in[g[ver][j]]--;
			val--;
			if(in[g[ver][j]]==0)
				s.insert(g[ver][j]);
		}
	}

	if(val!=0)
		printf("Sandro fails.\n");
	else {
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
		printf("\n");
	}
	return 0;
}
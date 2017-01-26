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

#define mod 1000000009
#define inf 999999999
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int tree[100010][2],t,m;
vector<int> g[100010];
int st[100010],end[100010],B[100010];
ii A[100000];
int tim;

void dfs(int i,int val) {
	st[i]=++tim;
	B[i]=val%2;

	for(int j=0;j<g[i].size();j++)
		dfs(g[i][j],val+1);
	end[i]=tim;
	// cout<<i<<" "<<st[i]<<" "<<end[i]<<endl;
}

void upd(int idx,int i) {
	while(idx<lim) {
		tree[idx][i]++;
		idx+=idx&-idx;
	}
}

int query(int idx,int i) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx][i];
		idx-=idx&-idx;
	}
	return sum;
}

int main() {
	inp(t);

	while(t--) {
		inp(m);

		int cnt=1;

		for(int i=0;i<=m;i++)
			g[i].clear();

		memset(tree,0,sizeof tree);

		for(int i=0;i<m;i++) {
			inp(A[i].first);
			inp(A[i].second);

			if(A[i].first==0) {
				g[A[i].second].push_back(cnt);
				cnt++;
			}
		}
		tim=0;
		dfs(0,0);

		int idx=1;
		upd(st[0],0);
		for(int i=0;i<m;i++) {
			if(A[i].first==0) {
				upd(st[idx],B[idx]);
				// cout<<"upd "<<st[idx]<<" "<<B[idx]<<endl;
				idx++;
			}
			else {
				int x=A[i].second;
				lli num=(lli)(query(end[x],0)-query(st[x]-1,0));
				// cout<<x<<" 0 quer : "<<num<<endl;
				num*=(num-1);

				lli ans=num/2;

				num=(lli)(query(end[x],1)-query(st[x]-1,1));
				num*=(num-1);
				ans+=num/2;
				printf("%lld\n", ans);
			}
		}

	}


	return 0;
}
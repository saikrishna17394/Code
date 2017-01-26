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
#include <cassert>

#define lli long long int
#define ii pair<int,int>

#define mod 1008
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

int t,n,A[301][301],B[301];
int cnt[301][301],vis[301];

bool solve(int idx) {
	if(idx==(n+1))
		return true;

	int val=0;
	for(int i=1;i<=n;i++) {
		if(vis[i]==1) {
			val++;
			continue;
		}
		bool ok=true;
		if(idx>1) {
			if(cnt[idx-1][i-1]<val || cnt[idx-1][i]<(idx-1-val))
				ok=false;
		}
		if(idx<n) {
			if(cnt[idx][i-1]<(i-1-val)  || cnt[idx][i]<(n-i-idx+1+val))
				ok=false;
		}
		if(!ok)
			continue;
		if(idx<1) {
			cnt[idx-1][i-1]-=val;
			cnt[idx-1][i]-=(idx-1-val);
		}
		if(idx<n) {
			cnt[idx-1][i-1]-=(i-1-val);
			cnt[idx][i]-=(n-i-idx+1+val);
		}

		vis[i]=1;
		B[idx]=i;
		if(solve(idx+1))
			return true;
		vis[i]=0;
		B[idx]=-1;

		if(idx<1) {
			cnt[idx-1][i-1]+=val;
			cnt[idx-1][i]+=(idx-1-val);
		}
		if(idx<n) {
			cnt[idx-1][i-1]+=(i-1-val);
			cnt[idx][i]+=(n-i-idx+1+val);
		}

	}
	return false;
}

int main() {
	inp(t);

	while(t--) {
		inp(n);

		memset(cnt,0,sizeof cnt);
		memset(vis,0,sizeof vis);

		for(int i=1;i<=n;i++) {
			for(int j=1;j<n;j++) {
				inp(A[i][j]);
				cnt[j][A[i][j]]++;
			}
		}

		assert(solve(1));
		for(int i=1;i<=n;i++)
			printf("%d ",B[i] );
		printf("\n");
	}

	return 0;
}
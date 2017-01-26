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

int t,n,A[100011],idx;
map<int,int> m;

int tree[100011][2];

void upd(int x,int i,int val) {
	while(x<idx) {
		tree[x][i]+=val;
		x+=x&-x;
	}
}

int read(int x,int i) {
	int sum=0;
	while(x>0) {
		sum+=tree[x][i];
		x-=x&-x;
	}
	return sum;
}


int main() {
	inp(t);

	while(t--) {
		inp(n);

		m.clear();
		memset(tree,0,sizeof tree);

		for(int i=0;i<n;i++) {
			inp(A[i]);
			m[A[i]]=1;
		}

		idx=1;

		for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
			it->second=idx++;

		for(int i=0;i<n;i++)
			upd(m[A[i]],1,1);

		lli ans=0;

		for(int i=0;i<n;i++) {
			int val=m[A[i]];
			upd(val,1,-1);
			ans+=(lli)read(val-1,0);
			ans+=(lli)read(idx-1,1);
			ans-=(lli)read(val,1);

			upd(val,0,1);
		}

		ans/=(lli)n;
		printf("%lld\n", ans);
	}

	return 0;
}
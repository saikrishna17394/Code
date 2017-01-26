#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
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

int t,n;
int tree[5001];

void upd(int idx,int val) {
	while(idx<=5000) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int query(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

int main() {
	// freopen("inp","r",stdin);

	// freopen("B-small-attempt0.in", "r", stdin);	
	freopen("B-large.in", "r", stdin);	

	freopen("out.txt", "w", stdout);


	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		memset(tree,0,sizeof tree);

		int x,y;

		for(int i=0;i<n;i++) {
			inp(x);
			inp(y);
			if(x>y)
				swap(x,y);

			upd(x,1);
			upd(y+1,-1);

			// cout<<x<<" "<<y+1<<endl;
		}

		printf("Case #%d:",a);

		int p;
		inp(p);

		while(p--) {
			inp(x);
			// cout<<x<<" "<<query(x)<<endl;
			printf(" %d",query(x));
		}
		printf("\n");
	}


	return 0;
}
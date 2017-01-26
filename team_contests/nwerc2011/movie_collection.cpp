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

int n,m,tree[200001],t;
int A[100001];

void upd(int idx,int val) {
	// cout<<idx<<" "<<val<<endl;
	while(idx<=(n+m)) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}


int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		int x;

		memset(tree,0,sizeof tree);
		for(int i=1;i<=n;i++) {
			A[i]=n-i+1;
			upd(A[i],1);
		}

		int idx=n+1;
		int t1=m;
		while(t1--) {
			inp(x);
			// cout<<x<<" w "<<A[x]<<endl;
			if(t1<(m-1))
				printf(" ");
			printf("%d",n-read(A[x]));
			upd(idx,1);
			upd(A[x],-1);
			A[x]=idx++;
		}
		printf("\n");
	}

	return 0;
}
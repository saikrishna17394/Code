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

int n,k,A[10000];

int dp[100001][51]={0};
int tree[100001][51]={0};

void update(int idx,int val,int i) {
	while(idx<=100001) {
		tree[idx][i]+=val;
		tree[idx][i]%=mod;
		idx+=idx&-idx;
	}
}

int read(int idx,int i) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx][i];
		idx-=idx&-idx;
	}
	return sum%mod;
}

int main() {
	inp(n);
	inp(k);

	for(int i=0;i<n;i++) {
		inp(A[i]);
		A[i]++;
	}

	for(int i=0;i<n;i++) {
		update(A[i],1,1);
		for(int j=2;j<=k;j++) {
			update(A[i],read(A[i]-1,j-1),j);
		}
	}
	printf("%d\n",read(100000,k));

	return 0;
}
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

int n,A[30001],tree[30001]={0},B[1000001];
int last[30001],q;
ii C[200000];
int ans[200000];
vector<ii> v[30001];

int read(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

void update(int idx,int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int main() {
	memset(B,-1,sizeof B);
	inp(n);

	for(int i=1;i<=n;i++) {
		inp(A[i]);
		last[i]=B[A[i]];
		B[A[i]]=i;
	}

	inp(q);

	for(int i=0;i<q;i++) {
		inp(C[i].second);
		inp(C[i].first);
		v[C[i].first].push_back(ii(C[i].second,i));
	}
	sort(C,C+q);

	int val=0;
	for(int i=1;i<=n;i++) {
		if(last[i]>0) {
			update(last[i],1);
			val++;
		}

		for(int j=0;j<v[i].size();j++) {
			ans[v[i][j].second]=i-v[i][j].first+1-(val-read(v[i][j].first-1));
		}
	}

	for(int i=0;i<q;i++)
		printf("%d\n", ans[i]);

	return 0;
}
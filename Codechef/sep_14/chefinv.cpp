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
#include <iomanip>
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

/*
This is a nice offline query problem with BIT.
Where I got TLE because I used maps to store the
results of offline queries.
Instead of maps using vector<ii> in a nice way,
the solution got accepted...!!
Even, I found out the number of inversions
using BIT.
*/


int n,m,A[200001],tree[200001]={0},ans[200001]={0};

lli ans1=0;
vector<ii> lt[200001],gt[200001];


void update(int idx,int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx) {
	int ret=0;
	while(idx>0) {
		ret+=tree[idx];
		idx-=idx&-idx;
	}
	return ret;
}



int main() {
	inp(n);
	inp(m);

	map<int,int> m2;
	for(int i=1;i<=n;i++) {
		inp(A[i]);
		m2[A[i]]=1;
	}

	int cnt=1;

	for(map<int,int>::iterator it=m2.begin();it!=m2.end();it++)
		it->second=cnt++;

	for(int i=1;i<=n;i++) {
		A[i]=m2[A[i]];
	}


	// printf("%lld\n", ans1);
	
	for(int i=1;i<=m;i++) {
		int a,b;
		inp(a);
		inp(b);

		if(a==b)
			continue;
		else if(a>b)
			swap(a,b);
		else
			;

		lt[a].push_back(ii(A[a],i));
		lt[b].push_back(ii(A[a],-i));
		gt[a].push_back(ii(A[a],-i));
		gt[b].push_back(ii(A[a],i));
		
		lt[a-1].push_back(ii(A[b],-i));
		lt[b-1].push_back(ii(A[b],i));
		gt[a-1].push_back(ii(A[b],i));
		gt[b-1].push_back(ii(A[b],-i));

		if(A[a]<A[b])
			ans[i]--;
		else if(A[a]>A[b])
			ans[i]++;
		else
			;
	}

	for(int i=0;i<=n;i++) {
		if(i>0) {
			update(A[i],1);
			ans1+=(lli)(i-read(A[i]));
		}

		for(int j=0;j<lt[i].size();j++) {
			int sign=lt[i][j].second/abs(lt[i][j].second);
			ans[abs(lt[i][j].second)]+=sign*(read(lt[i][j].first-1));
		}

		for(int j=0;j<gt[i].size();j++) {
			int sign=gt[i][j].second/abs(gt[i][j].second);
			ans[abs(gt[i][j].second)]+=sign*(i-read(gt[i][j].first));
		}
	}

	for(int i=1;i<=m;i++)
		printf("%lld\n", ans1+(lli)ans[i]);

	return 0;
}
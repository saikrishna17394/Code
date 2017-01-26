#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


int n,m;
int w[501];
int A[1000];
int tree[2000];
int pos[501];

void upd(int idx,int val) {
	while(idx<2000) {
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

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		cin>>w[i];

	int idx=1;
	memset(pos,-1,sizeof pos);
	memset(tree,0,sizeof tree);

	for(int i=0;i<m;i++) {
		cin>>A[i];
		if(pos[A[i]]==-1) {
			pos[A[i]]=n-idx+1;
			upd(pos[A[i]],w[A[i]]);
			idx++;
		}
	}

	idx=n+1;
	
	int ans=0;
	for(int i=0;i<m;i++) {
		int num=A[i];
		ans+=read(1999)-read(pos[num]);
		upd(pos[num],-w[A[i]]);

		pos[A[i]]=idx++;
		upd(pos[A[i]],w[A[i]]);
	}

	cout<<ans<<endl;

	return 0;
}
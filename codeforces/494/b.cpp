#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


string s,t;
int fault[100010],idx[100010];
lli dp[100010],tree[100010];
int n,m;

void upd(int idx,lli val) {
	while(idx<=m) {
		tree[idx]=(tree[idx]+val)%mod;
		idx+=idx&-idx;
	}
}

lli read(int idx) {
	lli sum=0;

	while(idx>0) {
		sum=(sum+tree[idx])%mod;
		idx-=idx&-idx;
	}
	return sum;
}

void setup() {
	int cur=0;
	fault[0]=0;
	for(int i=1;i<n;i++) {
		while(cur>0 && t[i]!=t[cur])
			cur=fault[cur-1];
		if(t[i]==t[cur])
			cur++;
		fault[i]=cur;
	}
}

void kmp() {
	int cur=0;

	for(int i=0;i<m;i++) {
		while(cur>0 && s[i]!=t[cur])
			cur=fault[cur-1];
		if(s[i]==t[cur])
			cur++;
		if(cur==n) {
			idx[i-n+1]=i-n+1;
		}
	}
}

int main(){ 
	cin>>s>>t;
	memset(dp,0,sizeof dp);
	memset(tree,0,sizeof tree);

	memset(idx,-1,sizeof idx);

	m=s.length();
	n=t.length();

	setup();
	kmp();

	for(int i=m-2;i>=0;i--) {
		if(idx[i]==-1)
			idx[i]=idx[i+1];
		// printf("%d ",idx[i] );
	}
	// printf("\n");

	lli ans=0;
	for(int i=m-1;i>=0;i--) {
		if(idx[i]==-1)
			continue;
		dp[i]=dp[i+1];
		int val=idx[i]+n;
		dp[i]+=read(m-val);
		dp[i]+=(m-val+1);
		dp[i]%=mod;
		upd(m-i,dp[i]);
		// upd(m-i,)
		// ans+=dp[i];
		// printf("%d: %lld\n",i,dp[i] );
	}
	// printf("\n");
	printf("%lld\n", dp[0]);
	return 0;
}
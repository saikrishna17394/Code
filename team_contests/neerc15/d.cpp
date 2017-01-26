#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<long long int,long long int> ii;

using namespace std;


map<pair<lli,ii>,lli> m;
lli dp[63],dp1[40];
lli A[63][40];

lli fun(lli n,lli a,lli b) {
	pair<lli,ii> p=make_pair(n,ii(a,b));

	if(m.find(p)!=m.end()) 
		return m[p];

	if(b==0) {
		for(int i=max(1,(int)a);dp[i]<=n;i++) {
			if(dp[i]==n) {
				m[p]=i+1;

				return i+1;
			}
		}
		m[p]=-1;
		return -1;
	}

	if(dp[a]>n) {
		m[p]=-1;
		return -1;
	}

	lli ret=fun(n,a,b-1);
	if(ret!=-1) {
		m[p]=0;
		return 0;
	}


	lli val=A[a][b];

	if(val==-1 || val>n) {
		m[p]=-1;
		return -1;
	}

	while(val<=n) {
		if(val==n) {
			m[p]=a+1;
			return a+1;
		}
		else {
			lli ret=fun(n-val,a+1,b-1);
			if(ret!=-1) {
				m[p]=a+1;
				return a+1;
			}
		}
		val*=(lli)2;
		a++;
	}

	m[p]=-1;
	return -1;
}


int main(){ 
	freopen("distribution.in", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("distribution.out", "w", stdout);

	lli t;
	lli n;

	lli big=1e18;

	dp[0]=1;
	dp1[0]=1;
	for(int i=1;i<63;i++)
		dp[i]=dp[i-1]+dp[i-1];
	for(int i=1;i<40;i++)
		dp1[i]=dp1[i-1]+dp1[i-1]+dp1[i-1];

	memset(A,-1,sizeof A);

	for(int i=0;i<61;i++) {
		A[i][0]=dp[i];
		for(int j=1;j<40;j++) {
			A[i][j]=A[i][j-1]*3;
			if(A[i][j]>big)
				break;
		}
	}

	cin>>t;

	while(t--) {
		cin>>n;

		if(n==1) {
			cout<<1<<endl;
			cout<<1<<endl;
			continue;
		}

		vector<lli> v;

		lli ret=fun(n,0,39);

		lli a=0;

		// cout<<n<<" ----------- "<<ret<<endl;
		for(lli i=39;i>=0;i--) {

			// cout<<n<<endl;
			pair<lli,ii> p=make_pair(n,ii(a,i));

			// cout<<n<<" "<<i<<" "<<b<<" - "<<m[p]<<endl;
			if(m[p]>0) {
				lli val=dp[m[p]-1];
				val*=dp1[i];
				v.push_back(val);

				n-=val;
				a=m[p];
			}
		}

		cout<<v.size()<<endl;

		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}

	return 0;
}
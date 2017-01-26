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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n;
lli dp[100000010];

vector<vector<lli> > mul(vector<vector<lli> > a,vector<vector<lli> > b) {
	vector<vector<lli> > ret=a;

	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			ret[i][j]=0;
			for(int k=0;k<2;k++)
				ret[i][j]+=(a[i][k]*b[k][j])%mod;
			ret[i][j]%=mod;
		}
	}
	return ret;
}

vector<vector<lli> > power(vector<vector<lli> > m,int n) {
	vector<vector<lli> > ret=m;
	ret[0][0]=1;ret[1][1]=1;
	ret[0][1]=0;
	ret[1][0]=0;

	while(n>0) {
		if(n%2==1)
			ret=mul(ret,m);

		m=mul(m,m);
		n/=2;		
	}
	return ret;
}

int main() {

	inp(t);

	vector<vector<lli> > m;
	dp[0]=2;
	dp[1]=5;


	m.resize(2);

	m[0].resize(2);
	m[1].resize(2);
	m[0][0]=2;
	m[0][1]=3;
	m[1][0]=1;
	m[1][1]=0;

	// for(int i=2;i<=100000000;i++)
	// 	dp[i]=(2*dp[i-1]+3*dp[i-2])%mod;

	while(t--) {
		inp(n);
		// cout<<dp[n]<<endl;
		if(n<2) {
			printf("%lld\n",dp[n] );
			continue;
		}
		vector<vector<lli> > m1;
		m1=power(m,n-1);

		// cout<<m1[0][0]<<" "<<m1[0][1]<<endl;

		lli ans=5*m1[0][0]+2*m1[0][1];
		printf("%lld\n", ans%mod);
	}

	return 0;
}
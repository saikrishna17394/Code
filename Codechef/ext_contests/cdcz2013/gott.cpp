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
int t,n,p[50],c[50],p_tot;
ii dp[50][5001];
string s;

ii ans(int i,int val) {

	if(i+1==n) {
		if(val>p[i])
			return ii(inf,0);

		if(val==0 && c[i]!=0)
			return ii(0,0);
		return ii(c[i],p[i]);
	}

	if(dp[i][val].first!=-1)
		return dp[i][val];

	ii & ret=dp[i][val];

	ii val1=ans(i+1,val);
	ii val2=ans(i+1,max(val-p[i],0));

	if((c[i]+val2.first)<val1.first) {
		ret.first=c[i]+val2.first;
		ret.second=p[i]+val2.second;
	}
	else if((c[i]+val2.first)==val1.first) {
		ret.first=val1.first;
		ret.second=max(val1.second,p[i]+val2.second);
	}
	else {
		ret.first=val1.first;
		ret.second=val1.second;
	}
	return ret;
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(p_tot);

		for(int i=0;i<n;i++) {
			cin>>s;
			inp(p[i]);
			inp(c[i]);
		}

		memset(dp,-1,sizeof dp);
		ii p=ans(0,p_tot);

		printf("%d %d\n", p.first,p.second);
	}


	return 0;
}
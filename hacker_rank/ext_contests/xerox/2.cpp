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
#define ii pair<long long int,long long int>

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
int n;
string s;
int dp[1000][1000];
vector<int> v[10];

int solve(int l,int r) {
	int& ret=dp[l][r];
	if(ret!=-1)
		return ret;

	if(l==r) {
		if(s[l]=='5')
			ret=1;
		else
			ret=0;
		return ret;
	}

	ret=max(solve(l+1,r),solve(l,r-1));

	int val=s[l]-'0'+s[r]-'0';

	if(val==10) {
		if((l+1)==r)
			ret=2;
		else
			ret=max(ret,2+solve(l+1,r-1));
	}

	if(s[l]=='5' || s[r]=='5')
		ret=max(ret,1);
	return ret;
}

int main() {
	cin>>s;
	n=s.length();

	memset(dp,-1,sizeof dp);


	printf("%d\n", solve(0,n-1));

	return 0;
}
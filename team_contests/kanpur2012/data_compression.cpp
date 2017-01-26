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
#define lim 1000100

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,dp[2000000],n,k;
int tree[1000100],A[28];
string s;
char x;

int solve(int i,int cur) {
	if(i==n) {
		if(cur!=k)
			return 0;
		return 1;
	}
	
}

int main() {
	char a='z'+1;
	
	inp(t);

	while(t--) {
		cin>>s;
		inp(k);
		cin>>x;
		if(x=='_')
			x=a;

		memset(tree,0,sizeof tree);
		memset(dp,-1,sizeof dp);
		n=s.length();

		for(int i=1;i<=27;i++)
			A[i]=i;
		int ans=solve(0,0);

	}

	return 0;
}
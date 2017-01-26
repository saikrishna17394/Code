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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int dp[30][30][30][30];
int t,n;
string s[4];

int solve(int a,int b,int c,int d) {
	if(a==n || b==n || c==n || d==n) {
		// cout<<a<<" "<<b<<" "<<c<<" "<<d<<" : ";
		// printf("0\n");
		return 0;
	}
	int &ret=dp[a][b][c][d];
	if(ret!=-1) {
		// cout<<a<<" "<<b<<" "<<c<<" "<<d<<" : ";
		// printf("%d\n", ret);
		return ret;
	}

	ret=solve(a,b,c,d+1);

	int a1=-1,b1=-1,c1=-1;

	for(int i=a;i<n;i++) {
		if(s[0][i]==s[3][d]) {
			a1=i;
			break;
		}
	}

	for(int i=b;i<n;i++) {
		if(s[1][i]==s[3][d]) {
			b1=i;
			break;
		}
	}

	for(int i=c;i<n;i++) {
		if(s[2][i]==s[3][d]) {
			c1=i;
			break;
		}
	}

	if(a1==-1 || b1==-1 || c1==-1) {
		// cout<<a<<" "<<b<<" "<<c<<" "<<d<<" : ";
		// printf("%d\n", ret);
		return ret;
	}

	ret=max(ret,1+solve(a1+1,b1+1,c1+1,d+1));
	// cout<<a<<" "<<b<<" "<<c<<" "<<d<<" : ";
	// printf("%d\n", ret);
	return ret;
}
int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<4;i++)
			cin>>s[i];

		memset(dp,-1,sizeof dp);
		printf("%d\n", solve(0,0,0,0));	
	}

	return 0;
}
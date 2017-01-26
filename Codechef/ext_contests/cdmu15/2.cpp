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
#define lim 1000010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


int dp[lim][26]={0};
string s;
int q;int a,b;

int main() {
	getline(cin,s);


	inp(q);

	for(int i=0;i<s.length();i++) {
		for(int j=0;j<26;j++)
			dp[i+1][j]=dp[i][j];
		dp[i+1][s[i]-'a']++;
	}

	while(q--) {
		char c;
		scanf(" %c",&c);
		inp(a);
		inp(b);

		printf("%d\n", dp[b][c-'a']-dp[a-1][c-'a']);
	}	

	return 0;
}
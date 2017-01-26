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
#define inf (lli)1e16

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

string s;

lli dp[11];

int A[26]={0};

int main() {
	cin>>s;

	dp[0]=1;

	for(lli i=1;i<11;i++)
		dp[i]=i*dp[i-1];

	lli ans=dp[s.length()];

	for(int i=0;i<s.length();i++)
		A[s[i]-'a']++;

	for(int i=0;i<26;i++)
		ans/=dp[A[i]];

	cout<<ans<<endl;

	return 0;
}
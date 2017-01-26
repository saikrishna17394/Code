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

int main() {
	cin.sync_with_stdio(false);

	int t,A[26];
	string s;
	cin>>t;

	while(t--) {
		cin>>s;
		memset(A,0,sizeof A);
		for(int i=0;i<s.length();i++) {
			A[s[i]-'a']=1;
		}
		int ans=0;

		for(int i=0;i<26;i++)
			ans+=A[i];
		printf("%d\n", ans);
	}

	return 0;
}
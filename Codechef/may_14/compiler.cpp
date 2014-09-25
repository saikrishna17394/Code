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

int t,ans,cnt;
string s;

int main() {
	inp(t);

	while(t--) {
		ans=0;
		cnt=0;
		cin>>s;

		for(int i=0;i<s.length();i++) {
			if(s[i]=='<')
				cnt++;
			else if(cnt==0)
				break;
			else
				cnt--;
			if(cnt==0)
				ans=i+1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
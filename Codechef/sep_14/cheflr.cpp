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

int t,ans;
string s;
int main() {
	inp(t);

	while(t--) {
		ans=1;
		cin>>s;
		for(int i=0;i<s.length();i++) {
			ans=(ans*2)%mod;
			if(i%2==0) {
				if(s[i]=='r')
					ans+=2;
			}
			else {
				if(s[i]=='l')
					ans--;
				else
					ans++;
			}
			ans%=mod;
			if(ans<0)
				ans+=mod;
		}
		printf("%d\n", ans);
	}

	return 0;
}
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

int main() {
	int t;

	inp(t);

	string s;

	while(t--) {
		cin>>s;

		int val=0;
		for(int i=0;i<s.length();i++) {
			if(i%2==0) {
				if(s[i]=='+')
					val++;
			}
			else {
				if(s[i]=='-')
					val++;
			}
		}
		val=min(val,(int)s.length()-val);

		printf("%d\n",val);
	}

	return 0;
}
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

int main() {
	int t,n;
	string s;

	inp(t);

	while(t--) {
		cin>>s;

		bool ok=true;
		n=s.length();

		for(int i=0;i<n;i++) {
			if(s[i]!=s[n-i-1]) {
				ok=false;
				break;
			}
		}

		if(ok)
			printf("1\n");
		else
			printf("2\n");
	}


	return 0;
}
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
#define ii pair<int,int>

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

int t;
char s[100010];

int main() {
	inp(t);

	while(t--) {
		scanf("%s",s);
		bool ok=false;
		int len=strlen(s);
		// cout<<len<<endl;
		len-=2;
		for(int i=0;i<len;i++) {
			if(s[i]=='0') {
				if(s[i+1]=='1' && s[i+2]=='0')
					ok=true;
			}
			else {
				if(s[i+1]=='0' && s[i+2]=='1')
					ok=true;
			}
		}

		if(ok)
			printf("Good\n");
		else
			printf("Bad\n");
	}


	return 0;
}
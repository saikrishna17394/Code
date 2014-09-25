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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

lli t,n,val,ans;
string s;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		cin>>s;

		val=0;
		ans=0;
		for(int i=0;i<n;i++) {
			if(s[i]=='1') {
				ans+=val;
				ans++;
				val++;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
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
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli t,n,c,i,big=0,big_cost,val;
	string ans,s;
	inp(t);

	while(t--) {
		big=0;
		big_cost=0;

		inp(n);

		while(n--) {
			cin>>s;
			inp(c);
			inp(i);
			val=c*(100+i);

			if(val>big) {
				big=val;
				big_cost=c;
				ans=s;
			}
			else if(val==big && c>big_cost) {
				big=val;
				big_cost=c;
				ans=s;
			}
			else
				;
		}
		cout<<ans<<endl;
	}


	return 0;
}
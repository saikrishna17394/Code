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
	int t,n,num,big,big1,ans,ans1,num1;
	bool ok;

	inp(t);

	while(t--) {
		inp(n);
		big=0;
		big1=0;
		ok=false;
		for(int i=0;i<n;i++) {
			inp(num);
			inp(num1);

			// cout<<num<<" "<<big1<<" "<<big<<" "<<num1<<endl;
			if(num>big1) {
				ok=true;
				big=num;
				ans=i+1;
			}
			else if(num1<big)
				;
			else
				ok=false;

			if(num1>big1)
				big1=num1;

			// cout<<i<<" "<<ans<<" "<<ok<<endl;

		}
		if(ok)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}

	return 0;
}
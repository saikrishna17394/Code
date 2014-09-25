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
#include <ctime>

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

int f(int a,int b) {
	// cout<<a<<" "<<b<<endl;
	if(a==b)
		return 0;
	if(a>b)
		swap(a,b);
	int k=b/a;

	if(b%a==0)
		return k-1;
	int val=f(a,b%a);

	if(val==0)
		return k;
	if(k<=val)
		return k-1;
	return k;
}
int main() {
	int t,n,a,b,ans;
	inp(t);

	while(t--) {
		inp(n);
		ans=0;
		while(n--) {
			inp(a);
			inp(b);
			ans^=f(a,b);
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
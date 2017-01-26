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

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int len(int n) {
	int ret=0;
	while(n) {
		ret++;
		n/=2;
	}
	return ret;
}

int q,x,y,black;
string s;

int solve(int x,int y,int a) {
	if(x>y)
		swap(x,y);
	int l1=len(x);
	int l2=len(y);

	int ret=0;
	for(int i=l2;i>l1;i--) {
		if(i%2==a)
			ret++;
		y/=2;
	}
	// cout<<l1<<" "<<l2<<" "<<ret<<endl;

	for(int i=l1;i>=1;i--) {
		if(i%2==a)
			ret+=2;
		if(x==y) {
			if(i%2==a)
				ret--;
			break;
		}
		x/=2;
		y/=2;
	}

	return ret;
}

int main() {
	inp(q);

	black=1;
	while(q--) {
		cin>>s;
		if(s[1]=='i') {
			black^=1;
			continue;
		}
		inp(x);
		inp(y);

		if(s[1]=='b')
			printf("%d\n", solve(x,y,black));
		else
			printf("%d\n", solve(x,y,black^1));
	}

	return 0;
}
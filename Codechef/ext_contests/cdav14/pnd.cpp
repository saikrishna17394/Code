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

#define mod 1008
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

bool check(lli n) {
	if(n==0)
		return true;
	vector<lli> v;
	while(n>0) {
		v.push_back(n%8);
		n/=8;
	}
	for(int i=0;i<v.size();i++)
		if(v[i]!=v[v.size()-i-1])
			return false;
	return true;
}

lli t,n;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		if(check(n))
			printf("1\n");
		else
			printf("-1\n");
	}
	return 0;
}
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
#define ii pair<long long int,long long int>

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
	map<int,int> m;
	int n,num;

	inp(n);

	while(n--) {
		inp(num);
		m[num]++;
	}

	if(m.size()==0) {
		printf("-1\n");
		return 0;
	}

	int ans=-1,val=0,fre=0;

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		if(it->second>val) {
			val=it->second;
			ans=it->first;
			fre=1;
		}
		else if(it->second==val) {
			fre++;
		}
		else;

	}
	if(fre>1)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}
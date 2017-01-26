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
	int t,n;

	inp(t);

	while(t--) {
		map<int,int> m,m1;
		inp(n);

		m.clear();
		m1.clear();
		int num;
		for(int i=0;i<n;i++) {
			inp(num);
			if(num>0)
				m[num];
			else if(num<0)
				m1[-num];
			else;

		}

		int ans=0;

		for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
			if(m1.find(it->first)!=m1.end())
				ans++;

		printf("%d\n", ans);
	}

	return 0;
}
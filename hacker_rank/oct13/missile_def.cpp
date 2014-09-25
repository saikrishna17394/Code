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
	int n,a,b,ans=0;
	set<ii> s,s1;
	ii p;
	inp(n);
	for(int i=0;i<n;i++) {
		inp(a);
		inp(b);
		s.insert(ii(a,b));
	}

	while(!s.empty()) {
		ans++;
		s1.clear();

		p=*(s.begin());

		for(set<ii>::iterator it=s.begin();it!=s.end();it++) {
			if((it->first-p.first)>=abs(it->second-p.second))
				p=*it;
			else
				s1.insert(*it);
		}
		s=s1;
	}

	printf("%d\n", ans);

	return 0;
}
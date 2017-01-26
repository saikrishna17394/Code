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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	char ch;

	ch=getchar();

	ch=getchar();

	vector<ii> v;

	while(ch!=']') {
		ii p;
		inp(p.first);
		inp(p.second);

		v.push_back(p);

		ch=getchar();	
	}

	// for(int i=0;i<v.size();i++) {
	// 	printf("%d %d\n", v[i].first,v[i].second);
	// }

	vector<ii> ans;

	bool ok=false;
	bool inc=false,dec=false;

	for(int i=1;i<v.size();i++) {
		int y=v[i].second-v[i-1].second;
		int x=v[i].first-v[i-1].first;

		if(!inc && !dec) {
			if(y>v[i-1].second) {
				ans.push_back(ii(v[i].first,-1));
				inc=true;
				dec=false;
			}
			if((-y)>v[i].second) {
				ans.push_back(ii(v[i].first,-1));
				inc=false;
				dec=true;
			}
		}
		else {
			if(inc && (-y)>v[i].second) {
				inc=false;
				ans[ans.size()-1].second=v[i-1].first;
			}
			else if(dec && y>v[i-1].second) {
				dec=false;
				ans[ans.size()-1].second=v[i-1].first;
			}
			else
				;

		}
	}


	if(ans.size()>0 && ans[ans.size()-1].second==-1)
		ans[ans.size()-1].second=v[v.size()-1].first;

	printf("[");
	for(int i=0;i<ans.size();i++) {
		if(i>0)
			printf(",");
		printf("(%d,%d)",ans[i].first,ans[i].second);
	}
	printf("]\n");
	return 0;
}
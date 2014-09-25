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
	int t,n,A[10000],num;
	map<int,string> m;
	set<int> s;
	string s1;
	inp(t);

	while(t--) {
		m.clear();
		s.clear();
		inp(n);
		for(int i=0;i<n;i++) {
			cin>>s1;
			inp(num);
			if(m.find(num)!=m.end())
				s.insert(num);
			m[num]=s1;
		}

		for(set<int>::iterator it=s.begin();it!=s.end();it++)
			m.erase(*it);

		if(m.size())
			cout<<m.begin()->second<<endl;
		else
			printf("Nobody wins.\n");
	}


	return 0;
}
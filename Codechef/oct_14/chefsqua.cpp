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

#define mod 1000000009
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
int n,ans;
ii A[2000];
map<ii,int> m;

int main() {
	inp(n);

	for(int i=0;i<n;i++) {
		inp(A[i].first);
		inp(A[i].second);
		m[A[i]]=1;
	}

	if(n==0)
		ans=4;
	else 
		ans=3;

	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int val=2;
			ii p1,p2;
			p1.first=A[j].second-A[i].second+A[i].first;
			p1.second=A[i].first-A[j].first+A[i].second;

			p2.first=A[j].first+p1.first-A[i].first;
			p2.second=A[j].second+p1.second-A[i].second;

			if(m.find(p1)!=m.end())
				val--;
			if(m.find(p2)!=m.end())
				val--;
			ans=min(ans,val);

			val=2;
			p1.first=A[i].second-A[j].second+A[i].first;
			p1.second=A[j].first-A[i].first+A[i].second;

			p2.first=A[j].first+p1.first-A[i].first;
			p2.second=A[j].second+p1.second-A[i].second;

			if(m.find(p1)!=m.end())
				val--;
			if(m.find(p2)!=m.end())
				val--;
			ans=min(ans,val);

		}
	}

	printf("%d\n", ans);
	return 0;
}
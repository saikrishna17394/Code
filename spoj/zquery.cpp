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

#define mod 5000000
#define inf 999999999
#define lim 100000
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,m,A[50000],a,b;
vector<int> v[100001];
vector<ii> q[50000];
int B[50000];

int main() {
	inp(n);
	inp(m);

	for(int i=0;i<n;i++)
		inp(A[i]);

	for(int i=0;i<m;i++) {
		inp(a);
		inp(b);
		a--;b--;
		q[b].push_back(ii(a,i));
		B[i]=0;
	}

	int ans=0;
	for(int i=0;i<n;i++) {
		ans+=A[i];
		v[A[i]-ans+n].push_back(i);
		
		vector<int>::iterator it;
		for(int j=0;j<q[i].size();j++) {
			it=lower_bound(v[n-ans].begin(),v[n-ans].end(),q[i][j].first);
			if(it!=v[n-ans].end())
				B[q[i][j].second]=i-*it+1;
		}
	}

	for(int i=0;i<m;i++)
		printf("%d\n", B[i]);

	return 0;
}
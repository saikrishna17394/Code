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

int t,n;
int A[500][500];
ii B[250001];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				inp(A[i][j]);
				B[A[i][j]]=ii(i,j);
			}
		}

		int ans=0;
		for(int i=2;i<=n*n;i++) {
			ans+=abs(B[i].first-B[i-1].first);
			ans+=abs(B[i].second-B[i-1].second);
		}
		printf("%d\n", ans);
	}

	return 0;
}
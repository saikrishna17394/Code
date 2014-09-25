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
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int t;
	int C[1001];
	inp(t);
	while(t--) {
		int n,m;
		inp(m);

		for(int i=1;i<=100;i++)
			C[i]=0;

		for(int i=0;i<m;i++) {
			int temp;
			inp(temp);
			C[temp] =1;
		}
		int cnt = 0;
		inp(n);
		for(int i=0;i<n;i++) {
			int temp;
			inp(temp);
			if(C[temp] == 1)
				cnt++;
		}

		int ans = max(n, m) - cnt;
		cout << ans << endl;
	}
	return 0;
}
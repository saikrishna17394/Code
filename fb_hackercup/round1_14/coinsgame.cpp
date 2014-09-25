#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
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
	freopen("coins_game.txt", "r", stdin);
	freopen("coins_game_out.txt", "w", stdout);

	int t,n,c,k,ans,num,val;

	inp(t);

	for(int i=1;i<=t;i++) {
		inp(n);
		inp(k);
		inp(c);

		ans=n;

		for(int x=1;x<=n;x++) {
			num=k-k%x;
			val=n-x;
			if(c>num) {
				if(k%x)
					val+=(x-k%x);
			}
			ans=min(ans,val);
		}

		printf("Case #%d: %d\n", i,ans+c);
	}
	return 0;
}
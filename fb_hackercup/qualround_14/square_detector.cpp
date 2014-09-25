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
#define ii pair<long long int,long long int>
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
	freopen("square_detector.txt", "r", stdin);
	freopen("square_detector_out.txt", "w", stdout);

	int t,n,cnt,x,y,k;
	bool ok;
	string s[20];
	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		for(int i=0;i<n;i++)
			cin>>s[i];
		cnt=0;
		ok=true;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(s[i][j]=='#') {
					cnt++;
					if(ok) {
						x=i;
						y=j;
						ok=false;
					}
				}
			}
		}

		k=sqrt(cnt);

		if(k*k!=cnt || x+k>n || y+k>n) {
			printf("Case #%d: NO\n",a);
			continue;
		}

		ok=false;
		for(int i=x;i<x+k;i++) {
			for(int j=y;j<y+k;j++) {
				if(s[i][j]=='.') {
					ok=true;
					break;
				}
			}
			if(ok)
				break;
		}
		if(ok)
			printf("Case #%d: NO\n",a);
		else
			printf("Case #%d: YES\n",a);
	}

	return 0;
}
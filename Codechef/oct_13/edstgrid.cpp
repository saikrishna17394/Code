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
	int t,n,m,c2,c3,ans,ans1;
	string s[100];
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(c2);
		inp(c3);
		ans=0;
		ans1=0;
		for(int i=0;i<n;i++) {
			cin>>s[i];
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(s[i][j]=='B')
					ans++;
			}
		}
		for(int i=1;i<n-1;i++) {
			for(int j=1;j<m-1;j++) {
				if(s[i][j]=='W')
					ans1++;
			}
		}

		if(ans*c3<ans1*c2) {
			printf("%d\n", ans);
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(s[i][j]=='B')
						printf("3 %d %d\n",i+1,j+1);
				}
			}
		}
		else {
			printf("%d\n", ans1);
			for(int i=1;i<n-1;i++) {
				for(int j=1;j<m-1;j++) {
					if(s[i][j]=='W')
						printf("2 %d %d\n",i+1,j+1);
				}
			}
		}
	}


	return 0;
}
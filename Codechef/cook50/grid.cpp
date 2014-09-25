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

int t,n,ans;
string s[1000];

int l[1000][1000],r[1000][1000];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			cin>>s[i];

		ans=0;

		for(int i=n-1;i>=0;i--) {
			for(int j=n-1;j>=0;j--) {
				if(i==n-1)
					l[i][j]=0;
				else {
					l[i][j]=l[i+1][j];
				}
				if(j==n-1)
					r[i][j]=0;
				else {
					r[i][j]=r[i][j+1];
				}

				if(s[i][j]=='#') {
					l[i][j]++;
					r[i][j]++;
				}
				if(l[i][j]==0 && r[i][j]==0)
					ans++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
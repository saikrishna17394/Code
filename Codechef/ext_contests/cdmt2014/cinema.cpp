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
int t,n,m,p,q;
string s[1000];
int l[1000][1000],d[1000][1000],ans;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(p);
		inp(q);

		for(int i=0;i<n;i++)
			cin>>s[i];

		memset(l,0,sizeof l);
		memset(d,0,sizeof d);

		for(int i=0;i<n;i++) {
			if(s[i][m-1]=='#')
				l[i][m-1]=1;
			for(int j=m-2;j>=0;j--) {
				if(s[i][j]=='#')
					l[i][j]=1+l[i][j+1];
				// l[i][j]
			}
		}

		ans=0;

		for(int j=0;j<m;j++) {
			if(l[n-1][j]>=q)
				d[n-1][j]=1;
			if(d[n-1][j]>=p)
				ans++;
			for(int i=n-2;i>=0;i--) {
				if(l[i][j]>=q)
					d[i][j]=1+d[i+1][j];
				if(d[i][j]>=p)
					ans++;
			}
		}

		printf("%d\n", ans);

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				// cout<<i<<" "<<j<<" "<<l[i][j]<<endl;
				// cout<<i<<" "<<j<<" "<<d[i][j]<<endl;	
				if(d[i][j]>=p)
					printf("%d %d\n",i,j );
			}
		}
	}

	return 0;
}
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

map<int,int> s[100001];
int a,b,n,m,p,ans;

int main() {
	inp(n);
	inp(m);
	inp(p);

	while(p--) {
		inp(a);
		inp(b);
		if(s[a].find(b)==s[a].end())
			s[a][b]=1;
		else
			s[a][b]=s[a][b]+1;
	}

	for(int i=1;i<=n;i++) {
		if(m==1) {
			printf("0\n");
			continue;
		}
		ans=m-1;
		if(s[i].find(m)!=s[i].end())
			ans+=s[i][m];
		if(s[i].find(1)!=s[i].end())
			ans-=s[i][1];

		for(map<int,int>::iterator it=s[i].begin();it!=s[i].end();it++) {
			// cout<<it->first<<" "<<it->second<<endl;
			if((it->first)==m)
				break;
			
			if((it->second)<=1)
				continue;

			if(s[i].find((it->first)+1)==s[i].end()) {
				ans=-1;
				break;
			}

			if((it->second)>(1+s[i][it->first+1])) {
				ans=-1;
				break;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
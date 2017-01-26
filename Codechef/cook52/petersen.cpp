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

int g[10][10];
int t,n;
string s;
int main() {
	memset(g,0,sizeof g);

	for(int i=0;i<10;i++) {
		if(i<5)
			g[i][i+5]=1;
		else
			g[i][i-5]=1;

		if(i<5) {
			g[i][(i+1)%5]=1;
			g[i][(i+4)%5]=1;
		}
		else {
			g[i][(i+2)%5+5]=1;
			g[i][(i+3)%5+5]=1;
		}
	}

	inp(t);

	while(t--) {
		cin>>s;
		n=s.length();
		int val=s[0]-'A';

		bool ok=true;
		
		int idx=val;

		string s1="";
		s1+=idx+'0';
		for(int i=1;i<n;i++) {
			int nxt=s[i]-'A';

			if(g[idx][nxt]==1)
				idx=nxt;
			else if(g[idx][nxt+5]==1)
				idx=nxt+5;
			else {
				ok=false;
				break;
			}
			s1+=idx+'0';
		}
		if(ok) {
			cout<<s1<<endl;
			continue;
		}
		ok=true;
		idx=val+5;
		s1="";
		s1+=idx+'0';
		for(int i=1;i<n;i++) {
			int nxt=s[i]-'A';
			if(g[idx][nxt]==1)
				idx=nxt;
			else if(g[idx][nxt+5]==1)
				idx=nxt+5;
			else {
				ok=false;
				break;
			}
			s1+=idx+'0';			
		}
		if(ok)
			cout<<s1<<endl;
		else
			printf("-1\n");
	}

	return 0;
} 

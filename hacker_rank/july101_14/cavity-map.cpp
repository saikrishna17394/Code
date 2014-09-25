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

string s[100];
int n;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main() {
	inp(n);

	for(int i=0;i<n;i++)
		cin>>s[i];

	for(int i=1;i<(n-1);i++) {
		for(int j=1;j<(n-1);j++) {
			bool ok=true;
			for(int k=0;k<4;k++) {
				char c=s[i+dx[k]][j+dy[k]];

				if(c=='X') {
					ok=false;
					break;
				}
				else if(c>=s[i][j]) {
					ok=false;
					break;
				}
				else
					;
			}
			if(ok)
				s[i][j]='X';
		}
	}

	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;
	return 0;
}
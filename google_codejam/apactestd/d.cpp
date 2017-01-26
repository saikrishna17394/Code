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

int t,n,ans;
char A[8][8];

int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={1,0,-1,1,0,-1,1,-1};

int kx[8]={2,2,-2,-2,1,1,-1,-1};
int ky[8]={1,-1,1,-1,2,-2,2,-2};

bool check(int x,int y) {
	if(x<0 || y<0 || x>=8 || y>=8)
		return false;
	return true;	
}

void king(int x,int y) {
	for(int a=0;a<8;a++) {
		int i=x+dx[a],j=y+dy[a];
		if(check(i,j) && A[i][j]!=0)
			ans++;
	}
}

void queen(int x,int y,int idx) {
	for(int a=0;a<8;a++) {
		int val=abs(dx[a])+abs(dy[a]);
		if(val==2 && idx==1)
			continue;
		if(val==1 && idx==2)
			continue;
		for(int b=1;b<8;b++) {
			int i=x+b*dx[a],j=y+b*dy[a];
			if(!check(i,j))
				break;
			if(A[i][j]!=0) {
				ans++;
				break;
			}
		}
	}
}

void pawn(int x,int y) {
	if(check(x+1,y+1) && A[x+1][y+1]!=0)
		ans++;
	if(check(x+1,y-1) && A[x+1][y-1]!=0)
		ans++;
}

void knight(int x,int y) {
	for(int a=0;a<8;a++) {
		int i=x+kx[a],j=y+ky[a];
		if(check(i,j) && A[i][j]!=0)
			ans++;
	}	
}
int main() {
	// freopen("inp","r",stdin);

	// freopen("D-small-attempt0.in", "r", stdin);	
	freopen("D-large-practice.in", "r", stdin);	

	freopen("out.txt", "w", stdout);


	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		memset(A,0,sizeof A);

		for(int i=0;i<n;i++) {
			string s;
			cin>>s;

			int x=s[0]-'A';
			int y=s[1]-'1';

			A[x][y]=s[3];
			// cout<<x<<" "<<y<<" "<<A[x][y]<<endl;
		}
		ans=0;

		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				if(A[i][j]==0)
					continue;
				// cout<<i<<" "<<j<<" "<<A[i][j]<<endl;
				if(A[i][j]=='K')
					king(i,j);
				else if(A[i][j]=='Q')
					queen(i,j,0);
				else if(A[i][j]=='R')
					queen(i,j,1);
				else if(A[i][j]=='B')
					queen(i,j,2);
				else if(A[i][j]=='N')
					knight(i,j);
				else
					pawn(i,j);
			}
		}
		printf("Case #%d: %d\n",a,ans);
	}


	return 0;
}
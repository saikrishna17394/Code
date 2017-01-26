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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int dx[]={+1,+1,+1,-1,-1,-1,0,0,0};
int dy[]={+1,-1,0,+1,-1,0,+1,-1,0};

string s[8];
int A[8][8];

bool check(int x,int y) {
	if(x<0 || y<0 || x>=8 || y>=8)
		return false;
	return true;
}

void rook(int x,int y) {
	for(int i=0;i<8;i++) {
		A[x][i]=1;
		A[i][y]=1;
	}
}

void bishop(int x,int y) {
	for(int i=0;i<8;i++) {
		if(check(x+i,y+i))
			A[x+i][y+i]=1;
		if(check(x-i,y-i))
			A[x-i][y-i]=1;
		if(check(x+i,y-i))
			A[x+i][y-i]=1;
		if(check(x-i,y+i))
			A[x-i][y+i]=1;
	}
}

void king(int x,int y) {
	for(int i=0;i<9;i++) {
		if(check(x+dx[i],y+dy[i]))
			A[x+dx[i]][y+dy[i]]=1;
	}
}

int main() {
	for(int i=0;i<8;i++)
		cin>>s[i];

	memset(A,0,sizeof A);

	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			if(s[i][j]=='R' || s[i][j]=='Q')
				rook(i,j);
			if(s[i][j]=='B' || s[i][j]=='Q')
				bishop(i,j);
			if(s[i][j]=='S')
				king(i,j);
		}
	}

	bool ok=true;
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			if(s[i][j]=='P') {
				for(int k=0;k<9;k++) {
					if(check(i+dx[k],j+dy[k])) {
						if(A[i+dx[k]][j+dy[k]]==0)
							ok=false;
					}
				}
			}
		}
	}

	if(ok)
		printf("CHECKMATE!\n");
	else
		printf("NOT YET!\n");
	
	return 0;
}
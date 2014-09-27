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

int t,m,r,c,val,val1=0;
int A[50][50];

int nbr(int i,int j) {
	int ret=0;
	if(i>0 && j>0 && A[i-1][j-1]==-1)
		ret++;
	if(i>0 && A[i-1][j]==-1)
		ret++;
	if(i>0 && j+1<c && A[i-1][j+1]==-1)
		ret++;
	if(j>0 && A[i][j-1]==-1)
		ret++;
	if(j+1<c && A[i][j+1]==-1)
		ret++;
	if(i+1<r) {
		if(j>0 && A[i+1][j-1]==-1)
			ret++;
		if(A[i+1][j]==-1)
			ret++;
		if(j+1<c && A[i+1][j+1]==-1)
			ret++;
	}
	return ret;
}
int dfs(int i,int j) {

}

int main() {
	freopen("inp.txt","r",stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("B-large.in","r",stdin);
	freopen("out.txt", "w", stdout);

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(r);
		inp(c);
		inp(m);

		val=m;
		val1=0;

		memset(A,0,sizeof A);

		if(r<c) {
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					if(val1<m) {
						A[i][j]=-1;
						val1++;
					}
				}
			}
		}
		else {
			for(int j=0;j<c;j++) {
				for(int i=0;i<r;i++) {
					if(val1<m) {
						A[i][j]=-1;
						val1++;
					}
				}
			}
		}

		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				if(A[i][j]!=-1) {
					A[i][j]=nbr(i,j);
					printf("%d",A[i][j] );
				}
				else
					printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}
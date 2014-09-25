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
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int n,A[1000][1000],ans=0;

int main() {
	inp(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			inp(A[i][j]);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(A[i][j])
				ans++;

	printf("%d\n", ans);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(A[i][j])
				printf("%d %d %d %d %d\n",A[i][j],i+1,i+1,j+1,j+1);

	return 0;
}
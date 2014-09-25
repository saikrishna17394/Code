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
	int t,n,a,b,w,val[100],tim[100],A[100][101];

	inp(t);

	while(t--) {
		inp(n);
		inp(w);

		for(int i=0;i<n;i++) {
			inp(a);
			inp(b);
			val[i]=a*b;
			inp(tim[i]);
		}

		for(int i=0;i<tim[0];i++)
			A[0][i]=0;
		for(int i=tim[0];i<=w;i++)
			A[0][i]=val[0];

		for(int i=1;i<n;i++) {
			for(int j=0;j<=w;j++) {
				A[i][j]=A[i-1][j];

				if(j>=tim[i])
					A[i][j]=max(A[i][j],val[i]+A[i-1][j-tim[i]]);
			}
		}
		printf("%d\n",A[n-1][w]);

	}

	return 0;
}
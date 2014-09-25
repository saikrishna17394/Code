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

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int lcm(int a,int b) {
	int ret=a*b;
	ret/=gcd(a,b);
	return ret;
}

int n,m,A[100][100],P[100][100];

vector<ii> ans[100];

int main() {
	inp(n);
	inp(m);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			inp(P[i][j]);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			inp(A[i][j]);

	int q=0;

	// for(int i=1;i<=n;i++) {
	// 	int k=lcm
	// }
	printf("%d\n", n*m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d %d %d %d %d\n",i,j,i,j,(P[i][j]-A[i][j])%P[i][j]);
	return 0;
}
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

#define mod 100000000
#define lim 100001

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli n,k,A[lim],C[lim],inf;
lli B[lim],dp[lim][11],idx[lim][11];


lli cost(lli l,lli r) {
	lli ret=B[r]-B[l-1];
	ret-=(C[r]-C[l-1])*l;
	return ret;
}

void solve(int j,int a,int b,int l,int r) {
	if(a>b)
		return;

	if(a==b) {
		dp[a][j]=inf;

		for(int i=l;i<=r;i++) {
			if(i>=a)
				break;
			lli val=dp[i][j-1]+cost(i+1,a);
			if(dp[a][j] >= val) {
				dp[a][j]=val;
				idx[a][j]=i;
			}
		}
		return;
	}
	int m=(a+b/2);

	dp[m][j]=inf;

	for(int i=l;i<=r;i++) {
		if(i>=m)
			break;
		lli val=dp[i][j-1]+cost(i+1,m);

		if(dp[m][j]>=val) {
			dp[m][j]=val;
			idx[m][j]=i;
		}
	}

	solve(j,a,m-1,l,idx[m][j]);
	solve(j,m+1,b,idx[m][j],r);
}

int main() {
	inf=(lli)(1e18);
	
	inp(n);
	inp(k);

	B[0]=0;
	C[0]=0;
	for(int i=1;i<=n;i++) {
		inp(A[i]);
		B[i]=B[i-1]+A[i]*i;
		C[i]=C[i-1]+A[i];
		dp[i][1]=cost(1,i);
	}

	for(int j=2;j<=(int)k;j++) 
		solve(j,j,(int)n,j-1,(int)n);

	cout<<dp[n][k]<<endl;
	// for(int j=1;j<=(int)k;j++) {
	// 	for(int i=j;i<=n;i++)
	// 		cout<<dp[i][j]<<" ";
	// 	printf("\n");
	// }
	return 0;
}
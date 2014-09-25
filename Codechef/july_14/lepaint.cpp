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
#define lim 100001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int t,n,k,c,a,b;

double dp[51][100],vals[51],ans;

int A[50];


int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(c);
		inp(k);

		memset(dp,0,sizeof dp);
		ans=0;

		dp[0][1]=1;

		double val=c;
		val=1/val;

		vals[0]=1;

		for(int i=1;i<=k;i++) {
			vals[i]=0;
			for(int j=0;j<c;j++) {
				for(int r=0;r<c;r++)
					dp[i][(j*r)%c]+=dp[i-1][j]*val;
			}
			double num=0;
			for(int j=0;j<c;j++) {
				num+=dp[i][j];
				vals[i]+=(double)j*dp[i][j];
			}
			cout<<"krish "<<num<<endl;
		}

		memset(A,0,sizeof A);

		for(int i=0;i<k;i++) {
			inp(a);
			inp(b);
			a--;

			for(int j=a;j<b;j++)
				A[j]++;
		}

		for(int i=0;i<n;i++)
			ans+=vals[A[i]];
		printf("%.6f\n", ans);
	}

	return 0;
}
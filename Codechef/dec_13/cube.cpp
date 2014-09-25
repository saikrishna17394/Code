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
int t,n,p,val;
char A[40][40][40],B[40][40][40],ch;
short dpx[40][40][40][41],dpy[40][40][40][41],dpz[40][40][40][41],dpxy[40][40][40][41];
short dpyz[40][40][40][41],dpzx[40][40][40][41],dp[40][40][40][41],cnt[41];

int main() {
	inp(t);

	for(int i=0;i<40;i++)
		for(int j=0;j<40;j++)
			for(int k=0;k<40;k++) {
				dp[i][j][k][0]=0;
				dpx[i][j][k][0]=0;
				dpy[i][j][k][0]=0;
				dpz[i][j][k][0]=0;
				dpxy[i][j][k][0]=0;
				dpyz[i][j][k][0]=0;
				dpzx[i][j][k][0]=0;
			}

	while(t--) {
		inp(n);
		inp(p);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					A[i][j][k]=getchar_unlocked();
		ch=getchar_unlocked();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					B[i][j][k]=getchar_unlocked();
		ch=getchar_unlocked();

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++) {
					if(A[i][j][k]==B[i][j][k]) {
						dpx[i][j][k][1]=1;
						dpy[i][j][k][1]=1;
						dpz[i][j][k][1]=1;
					}
					else {
						dpx[i][j][k][1]=0;
						dpy[i][j][k][1]=0;
						dpz[i][j][k][1]=0;						
					}
				}

		for(int l=2;l<=n;l++)
			for(int i=0;(i+l)<=n;i++)
				for(int j=0;j<n;j++)
					for(int k=0;k<n;k++) {
						dpx[i][j][k][l]=dpx[i][j][k][l-1]+dpx[i+l-1][j][k][1];
					}

		for(int l=2;l<=n;l++)
			for(int i=0;i<n;i++)
				for(int j=0;(j+l)<=n;j++)
					for(int k=0;k<n;k++) {
						dpy[i][j][k][l]=dpy[i][j][k][l-1]+dpy[i][j+l-1][k][1];
					}

		for(int l=2;l<=n;l++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					for(int k=0;(k+l)<=n;k++) {
						dpz[i][j][k][l]=dpz[i][j][k][l-1]+dpz[i][j][k+l-1][1];
					}

		for(int l=1;l<=n;l++)
			for(int i=0;(i+l)<=n;i++)
				for(int j=0;(j+l)<=n;j++)
					for(int k=0;k<n;k++) {
						dpxy[i][j][k][l]=dpxy[i][j][k][l-1];
						dpxy[i][j][k][l]+=(dpx[i][j+l-1][k][l]+dpy[i+l-1][j][k][l-1]);
					}

		for(int l=1;l<=n;l++)
			for(int i=0;(i+l)<=n;i++)
				for(int j=0;j<n;j++)
					for(int k=0;(k+l)<=n;k++) {
						dpzx[i][j][k][l]=dpzx[i][j][k][l-1];
						dpzx[i][j][k][l]+=(dpx[i][j][k+l-1][l]+dpz[i+l-1][j][k][l-1]);
					}

		for(int l=1;l<=n;l++)
			for(int i=0;i<n;i++)
				for(int j=0;(j+l)<=n;j++)
					for(int k=0;(k+l)<=n;k++) {
						dpyz[i][j][k][l]=dpyz[i][j][k][l-1];
						dpyz[i][j][k][l]+=(dpy[i][j][k+l-1][l]+dpz[i][j+l-1][k][l-1]);
					}

		memset(cnt,0,sizeof cnt);

		for(int l=1;l<=n;l++) {
			val=p*l*l*l;
			for(int i=0;(i+l)<=n;i++)
				for(int j=0;(j+l)<=n;j++)
					for(int k=0;(k+l)<=n;k++) {
						dp[i][j][k][l]=dp[i][j][k][l-1];
						dp[i][j][k][l]+=dpxy[i][j][k+l-1][l];
						dp[i][j][k][l]+=dpyz[i+l-1][j][k][l];
						dp[i][j][k][l]+=dpzx[i][j+l-1][k][l-1];
						dp[i][j][k][l]-=dpy[i+l-1][j][k+l-1][l];
						// cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;
						if((dp[i][j][k][l]*100)>=val)
							cnt[l]++;
					}
		}

		bool ok=true;
		for(int i=n;i>=1;i--) {
			if(cnt[i]) {
				printf("%d %d\n",i,cnt[i]);
				ok=false;
				break;
			}
		}
		if(ok)
			printf("-1\n");
	}

	return 0;
}
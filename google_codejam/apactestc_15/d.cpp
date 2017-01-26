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

int t,n,c,k,x;
int A[3001],B[3001];
int C[3001][3001];
int st[3010];

int dpl[3001][3001];
int dp[3001][3001];

lli ans=0;

int main() {
	// freopen("inp","r",stdin);
	// freopen("D-small-attempt0.in", "r", stdin);	
	freopen("D-large.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		inp(k);
		inp(c);
		inp(x);

		for(int i=1;i<=n;i++)
			inp(A[i]);
		for(int i=1;i<=n;i++)
			inp(B[i]);

		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				C[i][j]=(A[i]*i+B[j]*j+c)%x;
			}
		}
		ans=0;

		for(int j=1;j<=n;j++) {
			int ind=0;
			st[ind++]=1;
			for(int i=2;i<=k;i++) {
				while(ind>0) {
					int pos=st[ind-1];
					if(C[i][j]>=C[pos][j])
						ind--;
					else
						break;
				}
				st[ind++]=i;
			}
			dpl[1][j]=C[st[0]][j];
			int l=0;

			for(int i=2;(i+k-1)<=n;i++) {
				if(st[l]==(i-1))
					l++;

				while(ind>l) {
					int pos=st[ind-1];
					if(C[i+k-1][j]>=C[pos][j])
						ind--;
					else
						break;
				}
				st[ind++]=i+k-1;
				dpl[i][j]=C[st[l]][j];
			}
		}

		for(int i=1;(i+k-1)<=n;i++) {
			int ind=0,l=0;
			st[ind++]=1;

			for(int j=2;j<=k;j++) {
				while(ind>0) {
					int pos=st[ind-1];

					if(dpl[i][j]>=dpl[i][pos])
						ind--;
					else 
						break;
				}
				st[ind++]=j; 
			}
			ans+=(lli)dpl[i][st[0]];

			for(int j=2;(j+k-1)<=n;j++) {
				if(st[l]==(j-1))
					l++;

				while(ind>l) {
					int pos=st[ind-1];
					if(dpl[i][j+k-1]>=dpl[i][pos])
						ind--;
					else
						break;
				}
				st[ind++]=j+k-1;
				ans+=(lli)dpl[i][st[l]];
			}
		}
		printf("Case #%d: %lld\n",a,ans );

	}


	return 0;
}
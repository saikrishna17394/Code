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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli A[100010];
// map<ii,lli> m;

lli k,p1[31],p2[31];
int dp[31][31][31][31];


int main() {
	lli t,n;
	inp(t);
	while(t--) {
		inp(n);
		inp(k);

		for(int i=0;i<n;i++) {
			inp(A[i]);
		}
		sort(A,A+n);

		if(A[1]>k) {
			printf("0\n");
			continue;
		}
		if(A[n-2]==0 || A[1]==0 || (A[n-1]<=k && A[n-1]==1)) {
			printf("-1\n");
			continue;
		}
		lli ans=0;
		if(A[n-1]>k) {
			for(int i=1;i<n;i++)
				if(A[i]<=k)
					ans++;
		}
		else {
			ans=n-2;
			lli num=A[n-2];
			// while(num<=k) {
			// 	ans++;
			// 	num*=A[n-1];
			// }

			p1[0]=1;
			p2[0]=1;

			int a,b=-1;

			for(int i=1;i<31;i++) {
				p1[i]=A[n-1]*p1[i-1];
				if(p1[i]>k) {
					a=i;
					break;
				}
			}
			for(int i=1;i<31;i++) {
				p2[i]=A[n-2]*p2[i-1];
				if(p2[i]>k) {
					b=i;
					break;
				}
			}

			if(b==-1)
				b=1;

			for(int i1=a;i1>=0;i1--) {
				for(int j1=b;j1>=0;j1--) {
					for(int i2=a;i2>=0;i2--) {
						for(int j2=b;j2>=0;j2--) {
							int & ret=dp[i1][j1][i2][j2];
							if(p1[i1]>k || p2[j1]>k || p1[i2]>k || p2[j2]>k) {
								dp[i1][j1][i2][j2]=0;
								continue;
							}
							lli num1=p1[i1]*p2[j1];
							lli num2=p1[i2]*p2[j2];
							if(num1>k || num2>k) {
								ret=0;
								continue;
							}
							ret=dp[min(i1+i2,a)][min(j1+j2,b)][i2][j2];
							ret=min(ret,dp[i1][j1][min(i1+i2,a)][min(j1+j2,b)]);
							ret++;
						}
					}
				}
			}
			ans+=(lli)(dp[1][0][0][1]);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
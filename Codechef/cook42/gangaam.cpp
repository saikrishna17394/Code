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
#include <ctime>

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

ii A[400];
int B[201],C[201];
ii v[200];

int main() {
	int t,x,n,a,b;
	inp(t);

	while(t--) {
		inp(n);
		inp(x);
		int cnt=0;

		for(int i=0;i<n;i++) {
			inp(a);
			inp(b);
			A[cnt++]=ii(a,-i);
			A[cnt++]=ii(b,i);
			v[i]=
		}
		sort(A,A+cnt);
		int ans=0,val=0;

		memset(B,0,sizeof B);
		memset(C,0,sizeof C);

		for(int i=0;i<cnt;i++) {
			cout<<A[i].first<<" "<<A[i].second<<endl;
			if(A[i].second<0) {
				val++;
				B[-A[i].second]=1;
				if(val>=x) {
					ans++;
					// for(int j=1;j<=n;j++)
					// 	C[j]|=B[j];
				}
			}
			else {
				// B[A[i].second]=0;
				val--;
			}
		}

		// for(int i=1;i<=n;i++)
		// 	ans+=C[i];

		printf("%d\n", ans);
	}

	return 0;
}
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

int A[1002],B[1002],C[1002];


int main() {
	int t,x1,x2,y1,y2,a1,a2,b2,b1,ans;

	inp(t);

	while(t--) {
		inp(x1);
		inp(y1);
		inp(x2);
		inp(y2);


		inp(a1);
		inp(b1);
		inp(a2);
		inp(b2);

		ans=0;
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		memset(C,0,sizeof C);

		for(int i=y1;i<y2;i++)
			C[i]=1;
		for(int i=b1;i<b2;i++)
			C[i]++;
		int val=0;

		for(int i=0;i<1002;i++)
			val+=(C[i]/2);

		for(int i=x1;i<x2;i++)
			A[i]=1;
		for(int i=a1;i<a2;i++)
			B[i]=1;

		// cout<<val<<endl;
		for(int i=0;i<1002;i++) {
			if(A[i])
				ans+=(y2-y1);
			if(B[i])
				ans+=(b2-b1);

			if(A[i] && B[i]) {
				ans-=val;
			}
		}


		printf("%d\n", ans);
	}

	return 0;
}
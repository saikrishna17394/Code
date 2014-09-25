#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define x getchar_unlocked()
using namespace std;
 
inline void inp(int &n ) {//fast input function
    n=0;
    int ch=x,sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
    while( ch >= '0' && ch <= '9' )
    n=(n<<3)+(n<<1)+ ch-'0', ch=x;
    n=n*sign;
}
     
int main() {
	int t,n,A[50000],B[50000],big;
	lli ans;
	inp(t);
	while(t--) {
		inp(n);
		for(int i=0;i<n;i++)
			inp(A[i]);
		ans=0;
		if(n==1) {
			printf("0\n");
			continue;
		}

		big=A[n-1];
		for(int i=n-2;i>=0;i--) {
			ans+=max(0,big-A[i]);
			big=max(big,A[i]);
		}
		printf("%lld\n",ans);
	}

	return 0;
}
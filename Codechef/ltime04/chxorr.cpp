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

int value(int n) {
	int val=1;

	while(n>1) {
		val++;
		n>>=1;
	}
	return val;
}
int main() {
	int t,n,A[2000],ans,num,B[2000],big;

	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i]);
			B[i]=value(A[i]);
			big=max(big,B[i]);
		}
		ans=0;

		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				for(int k=j+1;k<n;k++) {
					num=A[i]^A[j];
					num^=A[k];
					ans=max(ans,num);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
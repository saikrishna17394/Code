#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	lli t,n,A[101]={0};
	inp(t);

	A[1]=1;
	A[2]=3;
	lli num=5;
	for(int i=3;i<101;i++,num+=2)
		A[i]=(A[i-1]*num)%mod;
	while(t--) {
		inp(n);
		printf("%lld\n",A[n]);

	}
	return 0;
}
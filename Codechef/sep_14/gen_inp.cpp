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
#include <iomanip>
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000000
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

int n,m,A[200000];


int main() {
	n=200000;
	m=200000;

	printf("%d %d\n", n,m);
	for(int i=0;i<n;i++) {
		A[i]=rand()%mod;
		A[i]++;
		printf("%d ",A[i]);
	}

	while(m--) {
		int a,b;
		a=rand()%n;
		a++;
		b=rand()%n;
		b++;
		printf("%d %d\n", a,b);
	}

	return 0;
}
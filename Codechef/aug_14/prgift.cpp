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

int t,n,k,A[50];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		int num=0;
		for(int i=0;i<n;i++) {
			inp(A[i]);
			if(A[i]%2==0)
				num++;
		}

		if(k) {
			if(num>=k)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {
			if(num<n)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}
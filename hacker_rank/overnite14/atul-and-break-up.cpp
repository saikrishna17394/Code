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

int A[100000],t,n;

int main() {
	int val=1,num=10;

	A[1]=1;

	for(int i=2;i<100000;i++) {
		if(i==num) {
			val++;
			num*=10;
		}

		A[i]=A[i-1]+i*val;
		if(A[i]>2000000000) {
			// cout<<i<<endl;
			break;
		}
	}

	inp(t);

	while(t--) {
		inp(n);
		for(int i=1;;i++) {
			if(A[i]>=n) {
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}
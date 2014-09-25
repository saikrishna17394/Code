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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int n,A[1000000],B[1000000];

int main() {
	inp(n);

	for(int i=0;i<n;i++)
		inp(A[i]);

	int cnt=1;
	B[0]=A[0];

	for(int i=1;i<n;i++) {
		int num=A[i]-i;

		if(num>=B[cnt-1]) {
			B[cnt++]=num;
			continue;
		}

		int l=0,r=cnt-1;

		while(l<r) {
			int mid=(l+r)/2;
			if(B[mid]>num) {
				r=mid;
			}
			else {
				l=mid+1;
			}

		}
		B[l]=num;
	}

	printf("%d\n", n-cnt);
	return 0;
}
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
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 1000010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n;
int A[lim];
int v[lim];

int main() {
	inp(n);

	for(int i=0;i<n;i++)
		inp(A[i]);

	int idx=1;

	v[0]=A[0];

	for(int i=1;i<n;i++) {
		if(A[i]>=v[idx-1])
			v[idx++]=A[i];
		else {
			int l=0,r=idx-1;

			while(l<r) {
				int m=(l+r)/2;
				if(A[i]<=v[m+1])
					l=m+1;
				else
					r=m;
			}
			v[l]=A[i];
		}
	}
	printf("%d\n", n-idx);
	return 0;
}
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

int A[15];
int B[100];

int main() {
	int p,n,m;

	inp(p);

	inp(n);
	inp(m);

	for(int i=0;i<n;i++)
		inp(A[i]);

	for(int i=0;i<m;i++)
		inp(B[i]);

	int val=-1,sum=0;

	if(m) {
		
		for(int i=0;i<n;i++) {
			if(A[i]>B[0]) {
				val=i;
				break;
			}
		}

	}
	if(val==-1)
		printf("%d 0",A[0]);

	else {
		int idx=0;
		for(int i=0;i<m;i++) {
			sum+=B[i];
			if(sum>=A[val])
				break;
			idx++;
		}
		printf("%d %d\n",A[val],idx);
		for(int i=0;i<idx;i++)
			printf("%d ",B[i]);
	}
	printf("\n");
	return 0;
}
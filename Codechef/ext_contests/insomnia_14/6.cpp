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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int n,m,A[100][100],num;

int main() {
	inp(n);
	inp(m);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			inp(A[i][j]);

	while(m--) {
		inp(num);
		num%=360;

		if(num==0) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++)
					printf("%d ", A[i][j]);			
				printf("\n");
			}
		}
		else if(num==90) {
			for(int j=0;j<n;j++) {
				for(int i=n-1;i>=0;i--)
					printf("%d ", A[i][j]);
				printf("\n");
			}
		}
		else if(num==180) {
			for(int i=n-1;i>=0;i--) {
				for(int j=n-1;j>=0;j--)
					printf("%d ", A[i][j]);			
				printf("\n");
			}
		}
		else {
			for(int j=n-1;j>=0;j--) {
				for(int i=0;i<n;i++) {
					printf("%d ", A[i][j]);			
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
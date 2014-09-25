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
int t,n,m,k;
int A[1000],B[1000][1000],C[1000][1000];
int diff[1000];

int main() {
	inp(t);
	while(t--) {
		inp(n);
		inp(m);
		inp(k);
		int ans=0;
		for(int i=0;i<n;i++) {
			inp(A[i]);
			A[i]--;
		}

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				inp(B[i][j]);
		}

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				inp(C[i][j]);
		}
		
		int val;
		for(int i=0;i<n;i++) {
			ans+=B[i][A[i]];
			val=0;
			for(int j=0;j<m;j++)
				val=max(val,B[i][j]-B[i][A[i]]-C[i][j]);
			diff[i]=val;
		}
		sort(diff,diff+n);
		for(int i=0;i<k;i++)
			ans+=diff[n-i-1];
		printf("%d\n", ans);
	}

	return 0;
}
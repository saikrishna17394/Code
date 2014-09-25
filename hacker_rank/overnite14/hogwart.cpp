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

int t,n,k,A[1000],B[1000],ans;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		for(int i=0;i<n;i++)
			inp(A[i]);
		for(int i=0;i<n;i++)
			inp(B[i]);
		ans=inf;
		sort(A,A+n);
		sort(B,B+n);

		int val=0;
		for(int i=0;i<n;i++)
			val+=A[i]*B[n-i-1];
		ans=min(ans,val);
		val=0;
		for(int i=0;i<n;i++)
			val+=B[i]*A[n-i-1];
		ans=min(ans,val);
		if(ans<=k)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
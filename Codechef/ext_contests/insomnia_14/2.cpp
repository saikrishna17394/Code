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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli k,t,n,m,A[500][500],ans;

int main() {
	inp(k);

	while(k--) {
		inp(t);
		ans=t+1;

		inp(n);
		inp(m);

		for(lli i=0;i<n;i++)
			for(lli j=0;j<m;j++)
				inp(A[i][j]);

		for(lli i=1;i<n;i++) {
			for(lli j=0;j<m;j++) {
				lli val=A[i-1][j];
				if(j>0)
					val=min(val,A[i-1][j-1]);
				if(j+1<m)
					val=min(val,A[i-1][j+1]);
				A[i][j]+=val;
				if(i+1==n)
					ans=min(ans,A[i][j]);
			}

		}

		if(ans<=t)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}
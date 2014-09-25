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
#define lim 1001
using namespace std;

inline bool inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
	if(ch=='\n' || ch==EOF)
		return true;
	return false;
}

int n,A[100000],v[100000],ans,k;

int main() {
	ans=0;

	inp(n);

	for(int i=0;i<n;i++)
		inp(A[i]);

	v[ans++]=A[0];

	for(int i=1;i<n;i++) {
		int l=0,r=ans-1;

		while(l<r) {
			int mid=(l+r)/2;

			if(v[mid]<=A[i])
				l=mid+1;
			else
				r=mid;			
		}

		if(v[l]<A[i])
			v[ans++]=A[i];
		else if(v[l]==A[i]) {
			if(v[ans-1]==A[i])
				v[ans++]=A[i];
			else
				v[l]=A[i];
		}
		else
			v[l]=A[i];
	}

	printf("%d\n", ans);
	return 0;
}
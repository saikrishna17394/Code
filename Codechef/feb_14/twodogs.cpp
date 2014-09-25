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
int n,T[1000000],l[1000001],r[1000001],k;

int main() {
	inp(n);
	inp(k);

	for(int i=0;i<n;i++) {
		inp(T[i]);
	}

	memset(l,-1,sizeof l);
	memset(r,-1,sizeof r);

	for(int i=0;i<n;i++) {
		if(l[T[i]]==-1)
			l[T[i]]=i+1;
	}

	for(int i=n-1;i>=0;i--) {
		if(r[T[i]]==-1)
			r[T[i]]=n-i;
	}

	int ans=inf;
	for(int i=1;i<=k;i++) {
		if(2*i==k)
			continue;
		if(l[i]==-1 || l[k-i]==-1)
			continue;

		int val1=min(l[i],r[i]);
		int val2=min(l[k-i],r[k-i]);
		ans=min(ans,max(val1,val2));
	}

	if(ans==inf)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
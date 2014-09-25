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

int t,n,A[1001],ans,k;

int main() {
	memset(A,0,sizeof A);

	A[0]=1;
	A[1]=0;

	for(int i=2;i*i<=lim;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=1;
		}
	}

	inp(t);

	while(t--) {
		// inp(k);
		k=28;
		inp(n);
		ans=0;
		for(int i=k;i<=n;i++) {
			if(A[i]==0)
				ans+=i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
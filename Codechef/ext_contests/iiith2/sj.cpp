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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli A[100000],pos,t,n,k,p;
	A[0]=0;
	A[1]=1;

	for(lli i=2;i<10000;i++) {
		A[i]=A[i-1]+i;
		// cout<<i<<" "<<A[i]<<endl;
		if(A[i]>=100000) {
			pos=i;
			// cout<<i<<endl;
			break;
		}
	}
	inp(t);

	while(t--) {
		inp(n);
		inp(p);
		inp(k);
		k=min(k,pos);

		if(n==0) {
			printf("0\n");
		}
		else if(p==0) {
			printf("%lld\n", n);
		}
		else {
			printf("%lld\n",max((lli)0,n-(A[k]+p)));
		}
	}
	return 0;
}
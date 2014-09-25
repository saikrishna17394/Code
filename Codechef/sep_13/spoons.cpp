#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	lli t,n,A[100],ans;

	A[2]=2;

	for(lli i=3;i<100;i++) {
		if(i%2==0) {
			A[i]=A[i-1]*2;
		}
		else {
			A[i]=(A[i-1]/((i+1)/2))*i;
		}

		//cout<<i<<" "<<A[i]<<endl;

		if(i==64)
			break;
	}
	inp(t);

	while(t--) {
		inp(n);

		int i=2;

		while(A[i]<n)
			i++;

		printf("%d\n",i);
	}

	return 0;
}
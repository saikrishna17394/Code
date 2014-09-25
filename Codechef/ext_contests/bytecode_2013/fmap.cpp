#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int t,n,h1,h2,A[10001],B[10001];

void up(int i) {
	if(A[i]==h1) {
		A[h1]=i;
		return;
	}

	int val=A[i];
	A[A[i]]=n;
	up(val);
	return;
}

int main(int argc, char const *argv[]) {
	inp(t);

	while (t--) {
		inp(n);
		inp(h1);
		inp(h2);

		for(int i=1;i<=n;i++) {
			if(i==h1)
				continue;
			inp(A[i]);
		}

		int cnt=0,ind=h2;
		B[cnt++]=h2;
		while(A[ind]!=h1) {
			B[cnt++]=A[ind];
			ind=A[ind];
		}
		B[cnt++]=h1;

		for(int i=cnt-1;i>0;i--) {
			A[B[i]]=B[i-1];
		}
		for(int i=1;i<=n;i++) {
			if(i==h2)
				continue;
			printf("%d ",A[i]);
		}

		printf("\n");
	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>
#include <algorithm>
#define x getchar_unlocked()
using namespace std;

inline void inp( int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}


int main() {
	int n,d,A[100000],ans=0;
	inp(n);
	inp(d);

	for(int i=0;i<n;i++)
		inp(A[i]);

	sort(A,A+n);
	for(int i=0;i<(n-1);i++) {
		if(A[i+1]-A[i]<=d){
			ans++;
			i++;
		}

	}

	printf("%d\n",ans);
	return 0;
}
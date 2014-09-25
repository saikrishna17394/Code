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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int t,n,q,r;

	inp(t);

	while(t--) {
		inp(n);
		if(n%3==0) {
			for(int i=0;i<n;i++)
				printf("5");
			printf("\n");
			continue;
		}

		if(n==5) {
			for(int i=0;i<n;i++)
				printf("3");
			printf("\n");
			continue;
		}

		if(n<8) {
			printf("-1\n");
			continue;
		}

		r=n%3;

		if(r==1) {
			for(int i=0;i<(n-10);i++)
				printf("5");

			for(int i=0;i<10;i++)
				printf("3");
			printf("\n");
		}

		else {
			for(int i=0;i<(n-5);i++)
				printf("5");

			for(int i=0;i<5;i++)
				printf("3");


			printf("\n");
		}

	}

	return 0;
}
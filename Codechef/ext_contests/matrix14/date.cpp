#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
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

int A[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int t,d,m,y;

int main() {
	inp(t);

	while(t--) {
		inp(d);
		inp(m);
		inp(y);

 
		if(y%4==0) {
			if(y%100!=0)
				A[1]++;
			else if(y%400==0)
				A[1]++;
			else
				;
		}
		if(d==0 || m==0 ||  m>12 || d>A[m-1] ) {
			printf("Invalid Date\n");
			continue;
		}

		if(d<A[m-1]) {
			d++;
			printf("%d/%d/",d,m );
			if(y<10)
				printf("000%d\n",y);
			else if(y<100)
				printf("00%d\n",y);
			else if(y<1000)
				printf("0%d\n",y );
			else
				printf("%d\n", y);

		}
		else {
			d=1;
			if(m<12) {
				m++;
				printf("%d/%d/",d,m);
				if(y<10)
					printf("000%d\n",y);
				else if(y<100)
					printf("00%d\n",y);
				else if(y<1000)
					printf("0%d\n",y );
				else
					printf("%d\n", y);
			}
			else {
				m=1;
				y++;
				printf("%d/%d/",d,m);
				y--;
				if(y<10)
					printf("000%d\n",y);
				else if(y<100)
					printf("00%d\n",y);
				else if(y<1000)
					printf("0%d\n",y );
				else
					printf("%d\n", y);

			}
		}

		if(y%4==0) {
			if(y%100!=0)
				A[1]--;
			else if(y%400==0)
				A[1]--;
			else
				;
		}

	}

	return 0;
}
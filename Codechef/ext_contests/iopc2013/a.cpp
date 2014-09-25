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

lli A[61],B[61];

int main() {
	lli t,n,b,q1,q2,r1,r2,num;

	inp(t);

	while(t--) {
		inp(n);
		inp(b);
		q1=1/b;
		q1=q1&1;
		r1=1%b;

		A[0]=q1;
		B[0]=r1;

		for(int i=2;i<61;i++) {
			A[i]=2*A[i-1];
			A[i]+=(B[i-1]*2)/b;
			A[i]&=1;
			B[i]=(B[i-1]*2)%b;
		}

		for(lli i=2;i<=n;i++) {
			q2=i/b;
			r2=i%b;

			q2=q2&1;

			q1=q1*q2+q1*r1+q2*r2;
			q1=q1&1;


			lli num=r2;

			int idx=0;

			while(num) {

				num>>=1;
				idx++;
			}


		}
	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
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
	int t,A[10000],a,b,val,n;
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(4);
	s.insert(6);
	inp(t);
	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			inp(A[i]);

		a=0;b=0;val=0;

		for(int i=0;i<n;i++) {
			if(A[i]<=36) {
				// a=1;

				if(A[i]>10 && s.find(A[i]%10)!=s.end())
				 	b=1;
				 else
				 	a=1;
			}
			else if(A[i]>=100) {
				val=1;
				break;
			}
			else {
				if(s.find(A[i]%10)!=s.end())
					a=1;
				else {
					val=1;
					break;
				}

			}
		}

		if(val==1)
			printf("THIEF\n");
		else if(a==0)
			printf("UNCLASSIFIABLE\n");
		else {
			for(int i=0;i<n;i++) {
				if(i)
					printf(" ");

				if(A[i]<36) {
					int num=(A[i]-1)/4+1;

					num*=10;

					val=(A[i]-1)%4;

					if(val==0)
						num+=1;
					else if(val==1)
						num+=3;
					else if(val==2)
						num+=4;
					else
						num+=6;

					printf("%d",num );

				}
				else
					printf("%d",A[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
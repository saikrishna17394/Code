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
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int A[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int B[12];
int main() {
	B[0]=A[0];
	for(int i=1;i<12;i++)
		B[i]=B[i-1]+A[i];

	int y,d,m;

	while(scanf("%d-%d-%d",&y,&m,&d)!=EOF) {
		// cout<<y<<" "<<m<<" "<<d<<endl;
		int val=11;

		int x=y/100;

		for(int i=17;i<=x;i++){
			if(i==x) {
				if(i%4!=0) {
					if(y%100!=0) {
						val++;
					}
					else {
						if(m>=3)
							val++;
					}
				}
				continue;
			}
			if(i%4!=0)
				val++;
		}
		
		// cout<<val<<endl;

		while(val>0) {
			int rem;
			if(m!=2)
				rem=A[m-1]-d+1;
			else if(y%4==0) {
				if(y%100==0) {
					if(y%400==0) 
						rem=29-d+1;
					else
						rem=28-d+1;
				}
				else
					rem=29-d+1;
			}
			else
				rem=28-d+1;

			if(val<rem) {
				d+=val;
				break;
			}
			d=1;
			val-=rem;
			if(m<12) {
				m++;
			}
			else {
				m=1;
				y++;
			}
		}


		printf("%d-",y);
		if(m<10)
			printf("0%d-",m );
		else
			printf("%d-",m );
		if(d<10)
			printf("0%d\n",d );
		else
			printf("%d\n",d );

	}

	return 0;
}
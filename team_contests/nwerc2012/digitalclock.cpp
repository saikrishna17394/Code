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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[10]={123,72,61,109,78,103,119,73,127,111};
int n,a,b;
ii B[50];

int C[50][4],D[4],E[4];

int main() {

	while(scanf("%d",&n)!=EOF) {
		// cout<<n<<" man\n";

		fill(D,D+4,0);

		for(int i=0;i<n;i++) {
			inp(a);

			C[i][0]=A[a/10];
			C[i][1]=A[a%10];
			inp(b);
			C[i][2]=A[b/10];
			C[i][3]=A[b%10];

			// cout<<a<<" "<<b<<endl;
			for(int j=0;j<4;j++)
				D[j]|=C[i][j];
		}

		// cout<<D[0]<<" w "<<D[1]<<" "<<D[2]<<" "<<D[3]<<endl;

		bool ok1=false;

		for(int i=0;i<24;i++) {
			for(int j=0;j<60;j++) {
				a=i;
				b=j;
				// cout<<i<<" "<<j<<endl;
				bool ok=true;
				for(int k=0;k<n;k++) {
					E[0]=A[a/10]&D[0];
					E[1]=A[a%10]&D[1];
					E[2]=A[b/10]&D[2];
					E[3]=A[b%10]&D[3];


					for(int d=0;d<4;d++) {
						if(E[d]!=C[k][d]) {
							ok=false;
							break;
						}
					}
					if(!ok)
						break;
					b++;
					if(b==60) {
						b=0;
						a=(a+1)%24;
					}
				}

				if(ok) {
					if(ok1)
						printf(" ");
					if(i<10) 
						printf("0%d:",i );
					else
						printf("%d:",i );
					if(j<10)
						printf("0%d",j );
					else
						printf("%d",j );

					ok1=true;
				}
			}
		}
		if(!ok1)
			printf("none\n");
		else
			printf("\n");
	}

	return 0;
}
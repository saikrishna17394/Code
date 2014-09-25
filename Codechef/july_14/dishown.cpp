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
#define lim 100001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}
int t,n,A[10001],par[10001],q,x,y,num;

int head(int x) {
	if(par[x]==x)
		return x;
	return par[x]=head(par[x]);
}


int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=1;i<=n;i++) {
			inp(A[i]);
			par[i]=i;
		}

		inp(q);

		while(q--) {
			inp(num);
			if(num==0) {
				inp(x);
				inp(y);

				int a=head(x);
				int b=head(y);

				if(a==b) {
					printf("Invalid query!\n");
				}
				else {
					if(A[a]>A[b])
						par[b]=a;
					else if(A[a]<A[b])
						par[a]=b;
					else
						;
				}
			}
			else {
				inp(x);
				printf("%d\n", head(x));
			}
		}

	}

	return 0;
}
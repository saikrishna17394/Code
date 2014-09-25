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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int A[100001],B[100001],t,n;

int main() {

	while(1) {
		inp(n);

		if(n==0)
			break;
		for(int i=1;i<=n;i++) {
			inp(A[i]);
			B[A[i]]=i;
		}

		bool ok=true;

		for(int i=1;i<=n;i++) {
			if(A[i]!=B[i]) {
				ok=false;
				break;
			}
		}

		if(ok)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 0;
}
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
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int n,t,A[lim],B[lim][4],a,b;

int main() {
	inp(n);
	inp(t);

	for(int i=0;i<n;i++)
		inp(A[i]);

	memset(B,-1,sizeof B);
	B[0][A[0]]=0;

	for(int i=1;i<n;i++) {
		for(int j=1;j<=3;j++) {
			if(A[i]==j)
				B[i][j]=i;
			else
				B[i][j]=B[i-1][j];
		}
	}

	while(t--) {
		inp(a);
		inp(b);
		// cout<<B[b][3]<<" "<<B[b][2]<<" "<<B[b][1]<<endl;
		for(int j=1;j<4;j++) {
			if(B[b][j]>=a) {
				printf("%d\n", j);
				break;
			}
		}
	}


	return 0;
}
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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
double A[101][101];

void find(int i,int j) {
	if(A[i][j]!=-1)
		return;

	double ans=0,den=(i+j),num;

	den*=den-1;

	num=2*i*j+i*(i-1);
	if(i>0) {
		find(i-1,j);
		ans=num*A[i-1][j];
	}

	if(j>1) {
		find(i+1,j-2);
		num=j*(j-1);
		ans=num*A[i+1][j-2];
	}

	den*=1.0;

	ans/=den;

	A[i][j]=ans;
}

int main() {

	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			A[i][j]=-1;
	A[0][0]=0;
	A[1][0]=0;
	A[0][1]=1.0;

	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			find(i,j);
			printf("%.7f ",A[i][j]);
		}
		printf("\n");
	}


	return 0;
}
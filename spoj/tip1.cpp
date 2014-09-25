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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int phi[10000000],A[10000000]={0},t,m,ans[lim];

bool check (int a,int b) {
	int A[10];
	memset(A,0,sizeof A);

	while(a) {
		A[a%10]++;
		a/=10;
	}
	while(b) {
		A[b%10]--;
		b/=10;
	}

	for(int i=0;i<10;i++)
		if(A[i]!=0)
			return false;

	return true;
}


int main() {
	phi[1]=1;

	for(int i=2;i*i<lim;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=i;
		}
	}

	ans[21]=21;
	for(int i=2;i<lim;i++) {
		if(A[i]==0)
			phi[i]=i-1;
		else {
			int num=i/A[i];
			if(num%A[i]==0)
				phi[i]=A[i]*phi[num];
			else
				phi[i]=(A[i]-1)*phi[num];
		}
	}

	for(int i=22;i<lim;i++) {
		if(A[i]==0)
			ans[i]=ans[i-1];
		else if((lli)ans[i-1]*(lli)phi[i]>=(lli)i*(lli)phi[ans[i-1]]) {
			if(check(i,phi[i]))
				ans[i]=i;
			else
				ans[i]=ans[i-1];
		}
		else
			ans[i]=ans[i-1];
	}
	inp(t);

	while(t--) {
		inp(m);
		if(m<=21)
			printf("No solution.\n");
		else
			printf("%d\n", ans[m]);
	}

	return 0;
}
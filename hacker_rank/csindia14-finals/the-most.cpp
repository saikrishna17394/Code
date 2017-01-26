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
#define ii pair<long long int,long long int>

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

int n,k,A[lim]={0},B[lim];

int C[lim]={0};

int main() {
	// printf("wh\n");
	
	for(int i=2;(i*i)<lim;i++) {
		// cout<<i<<" "<<A[i]<<endl;
		if(A[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=i;
		}
	}
	// printf("wh\n");
	B[1]=1;

	for(int i=2;i<lim;i++) {
		if(A[i]==0) {
			B[i]=2;
			continue;
		}

		int num=i,val=0;
		while(num%A[i]==0) {
			val++;
			num/=A[i];
		}
		B[i]=(val+1)*B[num];
	}

	inp(n);
	inp(k);
	int m;
	while(k--) {
		inp(m);
		C[m]+=B[m]%2;
	}

	for(int i=1;i<=n;i++)
		if(C[i]>0)
			printf("%d %d\n", i,C[i]);
	return 0;
}
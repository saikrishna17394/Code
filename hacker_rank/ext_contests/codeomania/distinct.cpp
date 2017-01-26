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
#define inf (lli)1e16
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

int t,n,A[lim]={0},dp[lim]={0};

int main() {
	inp(t);

	for(int i=2;i*i<lim;i++) {
		if(A[i]==0)	{
			for(int j=i*i;j<lim;j+=i)
				A[j]=i;
		}
	}

	for(int i=2;i<lim;i++) {
		if(A[i]==0)
			dp[i]=1;
		else {
			int num=i;
			while(num%A[i]==0)
				num/=A[i];
			dp[i]=1+dp[num];
		}
	}

	while(t--) {
		inp(n);
		printf("%d\n", dp[n]);
	}

	return 0;
}
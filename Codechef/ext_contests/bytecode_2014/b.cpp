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

#define mod 1008
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int t,n,k,A[100];

int idx[100001];
lli dp[100001][24];

int main() {
	// inp(t);
	A[1]=1;
	A[2]=1;
	idx[1]=0;
	int cnt=1;

	for(int i=3;i<100;i++) {
		A[i]=A[i-1]+A[i-2];
		if(A[i]>100000)
			break;
		// cout<<i<<" "<<A[i]<<endl;
		idx[A[i]]=cnt++;
	}
	// while(t--) {

	// }

	for(int j=0;j<24;j++) {
		dp[0][j]=0;
		
		for(int i=1;i<100001;i++) {
			dp[]
		}
	}
	inp(t);


	while(t--) {
		inp(n);
		inp(k);

	}
	return 0;
}
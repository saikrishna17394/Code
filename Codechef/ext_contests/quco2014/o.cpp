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
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


int t,n;
int dp[10001];

int B[50],idx;

int A[100];

int main() {

	dp[0]=1;

	B[0]=1;
	B[1]=2;
	
	for(int i=2;;i++) {
		B[i]=B[i-1]+B[i-2];
		if(B[i]>10000) {
			idx=i;
			break;
		}
		// cout<<B[i]<<endl;
	}

	dp[0]=0;

	for(int i=1;i<=10000;i++) {
		set<int> s;
		for(int j=0;j<idx;j++) {
			if(i<B[j])
				break;
			s.insert(dp[i-B[j]]);
		}

		int val=0;

		while(s.find(val)!=s.end())
			val++;
		dp[i]=val;
		// cout<<dp[i]<<endl;
	}


	inp(t);

	while(t--) {
		inp(n);

		int ans=0;

		for(int i=0;i<n;i++) {
			inp(A[i]);
			ans^=dp[A[i]];
			cout<<dp[A[i]]<<" "<<ans<<endl;
		}

		cout<<ans<<endl;
	}

	return 0;
}
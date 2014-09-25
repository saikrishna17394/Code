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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli dp[111][111],t,n;
int len;
lli A[111],B[111];

string s;
int main() {
	memset(dp,0,sizeof dp);

	dp[0][0]=1;
	A[0]=1;
	B[0]=1;
	inp(t);
	while(t--) {
		cin>>s;
		len=s.length();
		inp(n);

		if(n==1) {
			printf("0\n");
			continue;
		}

		for(int i=1;i<111;i++) {
			dp[i][0]=1;
			for(int j=1;j<=i;j++) {
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%n;
			}
		}

		for(int i=1;i<111;i++) {
			A[i]=(A[i-1]*2)%n;
			B[i]=(B[i-1]*10)%n;
		}

		lli ans=0;

		for(int i=0;i<len;i++) {
			lli val=0;
			lli num=s[i]-'0';
			for(int j=0;j<=i;j++) {
				val=val+((B[j]*dp[i][j])%n);
				val%=n;
			}
			val=(val*A[len-i-1])%n;
			val=(val*num)%n;
			ans+=val;
			ans%=n;
			// cout<<s[i]<<" "<<val<<endl;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
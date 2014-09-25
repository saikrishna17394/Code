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
int t,len,m;
string s;
lli dp[5001][5001][3],A[5000];

int main() {
	inp(t);

	while(t--) {
		cin>>s;
		inp(m);
		len=s.length();

		if(len<3) {
			printf("0\n");
			continue;
		}
		int idx;

		for(int j=0;j<=m;j++) {
			idx=0;
			dp[len][j][0]=0;
			for(int i=len-1;i>=0;i--) {
				if(s[i]=='a')
					A[idx++]=i;

				dp[i][j][0]=0;
				if(idx>=j) {
					if(idx==0 || j==0)
						dp[i][j][0]=dp[i+1][j][0]+(lli)(len-i);
					else
						dp[i][j][0]=dp[i+1][j][0]+(lli)(len-A[idx-j]);
				}
			}
		}

		for(int j=0;j<=m;j++) {
			idx=0;
			dp[len-1][j][1]=0;
			for(int i=len-2;i>=0;i--) {
				if(s[i]=='a')
					A[idx++]=i;

				dp[i][j][0]=0;
				if(idx>=j) {
					if(idx==0 || j==0)
						dp[i][j][0]=dp[i+1][j][0]+(lli)(len-i);
					else
						dp[i][j][0]=dp[i+1][j][0]+(lli)(len-A[idx-j]);
				}
			}
		}

	}


	return 0;
}
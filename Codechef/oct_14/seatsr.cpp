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

#define mod 1000000009
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

int t,a,b,k,dp[2][100100];

string s,w;

int main() {
	inp(t);

	while(t--) {
		cin>>s;
		cin>>w;
		inp(a);
		inp(b);
		inp(k);

		// b=min(b,2*a);
		int len_s=s.length(),len_w=w.length();

		if(a==0) {
			printf("0\n");
			continue;
		}
		if(b==0) {
			if(abs(len_s-len_w)*a<=k)
				printf("%d\n", a*abs(len_s-len_w));
			else
				printf("-1\n");
			continue;
		}


		for(int j=0;j<len_w;j++) {
			if(s[0]==w[j])
				dp[0][j]=j*a;
			else {
				if(j==0)
					dp[0][j]=min(b,2*a);
				else
					dp[0][j]=min(j*a+min(b,2*a),a+dp[0][j-1]);
			}
		}
		
		for(int i=1;i<len_s;i++) {
			for(int j=max(len_w-len_s+i-k,0);j<=min(len_w-1,len_w-len_s+i+k);j++) {
				if(j==0) {
					if(s[i]==w[j])
						dp[i%2][j]=i*a;
					else
						dp[i%2][j]=min(i*a+b,a+dp[(i-1)%2][j]);					
				}
				else {
					dp[i%2][j]=dp[(i-1)%2][j-1];
					if(s[i]!=w[j])
						dp[i%2][j]+=min(b,2*a);

					if(j!=(len_w-len_s+i+k))
						dp[i%2][j]=min(dp[i%2][j],dp[(i-1)%2][j]+a);
					if(j!=(len_w-len_s+i-k))
						dp[i%2][j]=min(dp[i%2][j],dp[i%2][j-1]+a);

				}
			}
		}

		if(dp[(len_s-1)%2][len_w-1]>k)
			printf("-1\n");
		else
			printf("%d\n",dp[(len_s-1)%2][len_w-1] );
	}

	return 0;
}
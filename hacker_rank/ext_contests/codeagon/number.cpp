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

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

string s;
int c,n;

lli dp[20][210][3];


int main() {
	cin>>s>>c;

	n=s.length();
	
	memset(dp,0,sizeof dp);

	// printf("brooooooo\n");
	int val=0;

	for(int i=n-1;i>=0;i--) {
		val+=(s[i]-'0');
		dp[i][0][val%3]++;
	}

	// dp[n-1][0][(s[n-1]-'0')%3]++;

	for(int j=1;j<=c;j++) {
		// printf("broo\n");
		for(int k=0;k<3;k++) {
			dp[n-1][j][k]=dp[n-1][j-1][k];
			// printf("%lld ",dp[n-1][j][k] );
		}
		// printf("\n");

		vector<int> v;

		int num=s[n-1]-'0';

		if((num+j)<10)
			v.push_back(num+j);

		if((num-j)>=0) {
			if(n==1) {
				if((num-j)!=0)
					v.push_back(num-j);
			}
			else
				v.push_back(num-j);
		}

		for(int a=0;a<v.size();a++) {
			// printf(" as %d\n", v[a]);
			dp[n-1][j][v[a]%3]++;
		}

		// cout<<n-1<<" "<<j<<" : \n";
		// for(int k=0;k<3;k++) {
		// 	printf("%lld ",dp[n-1][j][k] );
		// }
		// printf("\n");
	}


	for(int i=n-2;i>=0;i--) {

		for(int j=1;j<=c;j++) {

			
			for(int a=0;a<=min(9,j);a++) {
				vector<int> v;

				int num=s[i]-'0';

				if((num+a)<10)
					v.push_back(num+a);


				if((num-a)>=0 && a>0) {
					if(i==0) {
						if((num-a)!=0)
							v.push_back(num-a);
					}
					else
						v.push_back(num-a);
				}

				if(v.size()==0)
					break;

				for(int b=0;b<v.size();b++) {
					// printf(" abb %d\n", v[b]);
					for(int k=0;k<3;k++)
						dp[i][j][(k+v[b])%3]+=dp[i+1][j-a][k];
				}

			}

			// cout<<i<<" "<<j<<" : ";

			// for(int k=0;k<3;k++)
			// 	printf("%lld ",dp[i][j][k] );
			// printf("\n");
		}
	}

	cout<<dp[0][c][0]<<endl;

	return 0;
}
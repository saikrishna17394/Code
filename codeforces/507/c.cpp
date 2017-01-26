#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

lli dp[60];

int main(){ 
	// cin.sync_with_stdio(false);
	lli n,h;

	cin>>h>>n;

	lli ans=0;

	dp[0]=1;

	for(lli i=1;i<60;i++)
		dp[i]=dp[i-1]*(lli)2;
	
	int x=0;

	while(h>0) {

		// lli num=1<<(h-1);
		lli num=dp[h-1];

		if(n>num) {
			if(x==0) {
				ans+=(2*num-1);
				n-=num;
			}
			else {
				n-=num;
				x^=1;
			}
		}
		else {
			if(x==1)
				ans+=(2*num-1);
			else
				x^=1;
		}

		ans++;
		// cout<<h<<" "<<ans<<endl;
		h--;
	}
	// ans++;

	cout<<ans<<endl;
	return 0;
}
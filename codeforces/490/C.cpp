#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

string s;
int n;
int dp[1000001],a,b;

int main(){ 
	cin.sync_with_stdio(false);
	
	cin>>s;
	cin>>a>>b;
	n=s.length();

	dp[0]=1%b;
	for(int i=1;i<1000001;i++)	
		dp[i]=(dp[i-1]*10)%b;

	int idx=-1;

	int rem=0;

	for(int i=1;i<n;i++) {
		rem=rem*10;
		rem+=s[i]-'0';
		rem%=b;
	}

	int rem1=0;
	for(int i=0;i<(n-1);i++) {
		rem1=rem1*10;
		rem1+=s[i]-'0';
		rem1%=a;

		// cout<<i<<" "<<rem<<" "<<rem1<<endl;
		if(rem1==0 && rem==0 && s[i+1]!='0'){
			idx=i;
			break;
		}
		rem-=(dp[n-i-2]*(s[i+1]-'0'))%b;
		rem%=b;
		if(rem<0)
			rem+=b;
	}
	if(idx==-1) {
		printf("NO\n");
	}
	else {
		printf("YES\n");

		for(int i=0;i<=idx;i++)
			printf("%c",s[i] );

		printf("\n");
		for(int i=idx+1;i<n;i++)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<long long int,long long int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


string s;
int dp[lim];

int n,m;

map<string,int> M;

int main(){ 
	// cin.sync_with_stdio(false);
	int n,m;

	string s;

	cin>>n>>m;

	cin>>s;

	for(int i=0;i<26;i++) {
		string s1="";
		s1+=('a'+i);
		M[s1]=1;

		for(int j=0;j<26;j++) {
			string s2=s1;
			s2+=('a'+j);
			M[s2]=1;
		}
	}

	while(m--) {
		string s1;
		int val;
		cin>>s1>>val;
		M[s1]=val;
	}

	string s1="";
	
	dp[0]=M[(s1+s[0])];

	for(int i=1;i<n;i++) {
		string s2="";
		s2+=s[i];
		dp[i]=M[s2]+dp[i-1];

		s2="";
		s2+=s[i-1];
		s2+=s[i];
		if(i>1)
			dp[i]=max(dp[i],dp[i-2]+M[s2]);
		else
			dp[i]=max(dp[i],M[s2]);

		// cout<<i<<" "<<dp[i]<<endl;
	}


	cout<<dp[n-1]<<endl;
	return 0;
}
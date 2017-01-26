#include <bits/stdc++.h>
#define pll pair<long long int,long long int>
#define lli long long int
#define inf 999999999
#define mod 1000000009

using namespace std;

lli dp[1000001][2][2];
int A[1000000][3],t,n;
string s[3];

pll solve(int a,int b) {
	pll ret;
	
	if(a==-33) {
		if(b==-33) {
			ret.first=(lli)(13*25);
			ret.second=(lli)26;
		}
		else {
			ret.first=(lli)max(b-1,0);
			ret.second=(lli)min(1,b);
		}
	}
	else {
		if(b==-33) {
			ret.first=(lli)(26-a);
			ret.second=(lli)min(a,1);
		}
		else {
			if(a<b)
				ret.first=1;
			else
				ret.first=0;
			if(a==b)
				ret.second=1;
			else
				ret.second=0;
		}
	}
	
	return ret;
}


int main() {
	cin.sync_with_stdio(false);
	
	cin>>t;
	
	while(t--) {
		n=0;
		for(int i=0;i<3;i++) {
			cin>>s[i];
			n=max(n,(int)s[i].length());
		}
		
		for(int i=0;i<3;i++) {
			for(int j=0;j<s[i].length();j++)
				A[j][i]=s[i][j]-'a'+1;
			for(int j=s[i].length();j<n;j++)
				A[j][i]=0;
		}
		cout<<A[0][0]<<endl;

		dp[n][1][1]=1;
		dp[n][0][0]=0;
		dp[n][0][1]=0;
		dp[n][1][0]=0;
		
		for(int i=n-1;i>=0;i--) {
			lli val=1;
			for(int j=0;j<3;j++)
				if(A[i][j]==-33)
					val*=26;
			
			dp[i][1][1]=(val*dp[i+1][1][1])%mod;
			
			
			//1,0
			
			val=1;
			if(A[i][0]==-33)
				val=26;
				
			pll p=solve(A[i][1],A[i][2]);
			
			dp[i][1][0]=(p.first*dp[i+1][1][1])%mod;
			dp[i][1][0]+=(p.second*dp[i+1][1][0])%mod;
			dp[i][1][0]=(dp[i][1][0]*val)%mod;
			
			//0,1
			
			val=1;
			if(A[i][2]==-33)
				val=26;
			
			pll p1=solve(A[i][0],A[i][1]);
			
			dp[i][0][1]=(p1.first*dp[i+1][1][1])%mod;
			dp[i][0][1]+=(p1.seond*dp[i+1][0][1])%mod;
			dp[i][0][1]=(dp[0][1]*val)%mod;
			
			//0,0
			
			int a=A[i][0],b=A[i][1],c=A[i][2];
			
			
			
					
		}
		
		cout<<dp[0][0][0]<<endl;
	}
	
	return 0;
}

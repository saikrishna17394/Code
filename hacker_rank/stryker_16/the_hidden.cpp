#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

string t,p[200],s;
int n=0,s_len,t_len;
int A[200];

int dp[201][lim];

int solve(int i,int j) {
	if(i==s_len)
		return t_len-j;
	if(j==t_len)
		return s_len-i;

	int & ret = dp[i][j];
	if(ret!=-1)
		return ret;

	if(s[i]==t[j])
		ret = solve(i+1, j+1);
	else
		ret = 1 + min(solve(i, j+1),solve(i+1, j));
	
	return ret;
}


int main() {
	cin>>t;

	while(cin>>p[n]) {
		n++;
	}

	int idx = 0;
	for(int i = 0; i < n; i++) {

		int start_idx = -1;

		for(int j = idx; (j + p[i].length()) <= t.length(); j++) {
			bool ok = true;

			for(int k = 0; k < p[i].length() ;k++) {
				if(p[i][k] != t[j+k]) {
					ok = false;
					break;
				}
			}

			if(ok) {
				start_idx = j;
				idx = j+1;
				break;
			}
		}

		A[i] = start_idx;
	}

	if(A[n-1] == -1)
		printf("NO\n");
	else
		printf("YES\n");

	if(A[0] == -1) {
			printf("0\n");
	}
	else {
		for(int i = 0; i < n; i++) {
			if(A[i] == -1)
				break;
			cout<<p[i]<<" "<<A[i]<<" "<<A[i]+p[i].length()-1<<" ";
		}
		printf("\n");
	}

	if(A[n-1] == -1) {
		printf("0\n");
	}
	else{
		s="";

		for(int i = 0; i < n; i++) {
			s+=p[i];
			if(i<(n-1))
				s+=' ';
		}

		s_len=s.length();t_len=t.length();

		memset(dp,-1,sizeof dp);

		printf("%d\n", solve(0,0));
	}
	return 0;
}
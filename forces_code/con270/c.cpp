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
#define lim 10000000

using namespace std;


int n,A[100000],B[100000][2],p[100000],dp[100000][2];
string s[100000][2];

map<string,int> m;

int main() {
	cin>>n;
	
	for(int i=0;i<n;i++) {
		cin>>s[i][0]>>s[i][1];
		m[s[i][0]]=1;
		m[s[i][1]]=1;
	}

	int idx=0;

	for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
		it->second=idx++;

	for(int i=0;i<n;i++) {
		B[i][0]=m[s[i][0]];
		B[i][1]=m[s[i][1]];
	}		

	for(int i=0;i<n;i++) {
		cin>>p[i];
		p[i]--;
	}

	memset(dp,0,sizeof dp);

	dp[0][0]=1;
	dp[0][1]=1;

	for(int i=1;i<n;i++) {
		int cur=p[i],prev=p[i-1];

		if(dp[i-1][0]==1) {
			if(B[prev][0]<B[cur][0])
				dp[i][0]=1;
			if(B[prev][0]<B[cur][1])
				dp[i][1]=1;
		}
		if(dp[i-1][1]==1) {
			if(B[prev][1]<B[cur][0])
				dp[i][0]=1;
			if(B[prev][1]<B[cur][1])
				dp[i][1]=1;
		}
	}

	if(dp[n-1][0]==1 || dp[n-1][1]==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
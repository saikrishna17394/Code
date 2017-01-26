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

int n,x,y,A[100010],B[100010];

int dp[100010];

bool cmp(ii a,ii b) {
	if(a.first>=b.first)
		return true;
	return false;
}

int main() {
	inp(n);
	inp(x);
	inp(y);

	for(int i=0;i<n;i++)
		inp(A[i]);

	for(int i=0;i<n;i++)
		inp(B[i]);

	// int a=0,b=0;

	vector<ii> v1,v3;

	for(int i=0;i<n;i++) {
		if(A[i]>B[i])
			v1.push_back(ii(A[i],i));
		else if(A[i]==B[i])
			;// v2.push_back(ii(A[i],i));
		else
			v3.push_back(ii(B[i],i));
	}

	sort(v1.begin(),v1.end());
	sort(v3.begin(),v3.end());

	memset(dp,-1,sizeof dp);

	for(int i=0;i<v1.size();i++) {
		if(i<x) {
			dp[v1[v1.size()-i-1].second]=0;
		}
	}

	// sort(v3.begin(),v3.end(),cmp);

	for(int i=0;i<v3.size();i++) {
		if(i>=y) {
			dp[v3[v3.size()-i-1].second]=0;
		}
	}

	int ans=0;

	for(int i=0;i<n;i++) {
		if(dp[i]==0)
			ans+=A[i];
		else
			ans+=B[i];
	}

	cout<<ans<<endl;

	return 0;
}
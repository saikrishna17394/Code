#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,A[1000];
set<int> dp[1010];


set<int> solve(set<int> a,set<int> b) {

	set<int>::reverse_iterator it1=a.rbegin(),it2=b.rbegin();

	while(1) {
		if(it1==a.rend())
			return b;
		if(it2==b.rend())
			return a;
		if((*it1)>(*it2))
			return a;
		else if((*it1)<(*it2))
			return b;
		else
			;
		it1++;
		it2++;
	}	
}
int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i];


	dp[n-2].insert(max(A[n-1],A[n-2]));
	
	for(int i=n-3;i>=0;i--) {
		int a=max(A[i],A[i+1]);

		set<int> s1=dp[i+2];
		s1.insert(a);
		set<int> s2=dp[i+3];
		s2.insert(max(a,A[i+2]));

		dp[i]=solve(s1,s2);
		// cout<<i<<" : ";

		// for(set<int>::iterator it=dp[i].begin();it!=dp[i].end();it++)
		// 	cout<<(*it)<<" ";
		// printf("\n");
	}	


	for(set<int>::reverse_iterator it=dp[0].rbegin();it!=dp[0].rend();it++)
		cout<<*it<<endl;

	return 0;
}
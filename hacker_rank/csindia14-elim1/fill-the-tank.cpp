#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define inf 1<<40
#define lim 1000001
#define lli long long int
#define pli	pair<long long int,int>
using namespace std;

int b,q;
lli A[50],c,dp[1000001];
set<pli> s;

int main() {
	cin>>b>>q;
	
	for(int i=0;i<b;i++)
		cin>>A[i];
	fill(dp,dp+lim,(lli)inf);
	
	s.insert(pli(0,0));
	dp[0]=0;

	while(!s.empty()) {
		pli p=*s.begin();
		s.erase(s.begin());

		for(int i=0;i<b;i++) {
			int idx1=(p.second+(int)A[i])%(int)A[0];
			if(p.first+A[i]<dp[idx1]) {
				s.erase(pli(dp[idx1],idx1));
				dp[idx1]=p.first+A[i];
				s.insert(pli(dp[idx1],idx1));
			}
		}
	}

	while(q--) {
		scanf("%lld",&c);
		if(dp[c%A[0]]>c)
			printf("no\n");
		else
			printf("yes\n");
	}

	return 0;
}
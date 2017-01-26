#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define inf 1<<30

using namespace std;

int n,t,A[100],dp[100][100],B[100][100];

int main() {
	cin>>n>>t;

	for(int i=0;i<n;i++)
		cin>>A[i];

	int l=0,r=inf;

	while(l<r) {
		int mid=(l+r)/2;

		for(int i=0;i<n;i++) {
			dp[i][i]=0;
			B[i][i]=A[i];
		}


		for(int a=2;a<=n;a++) {
			for(int i=0;(i+a)<=n;i++) {
				B[i][i+a-1]=A[i]+B[i+1][i+a-1];
				dp[i][i+a-1]=inf;

				for(int j=i;j<(i+a-1);j++) {
					int val=B[i][j]*(j-i+1);
					val+=B[j+1][i+a-1]*(a+i-j-1);
					if(val>=mid)
						val-=mid;
					else
						val=0;
					val+=dp[j+1][i+a-1];
					val+=dp[i][j];
					dp[i][i+a-1]=min(dp[i][i+a-1],val);
				}
			}
		}
		if(dp[0][n-1]<=t)
			r=mid;
		else
			l=mid+1;
	}

	printf("%d\n", l);

	return 0;
}
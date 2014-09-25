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

int n;
double A[100];

int main() {
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n);

	if(A[n-1]>=0.5)
		printf("%.9f\n", A[n-1]);
	else {
		double ans=A[0];

		for(int i=1;i<n;i++) {
			// if(ans>=0.5)
			// 	break;
			ans=ans*(1.0-A[i])+A[i]*(1.0-ans);
		}

		printf("%.11f\n", ans);

	}

	return 0;
}
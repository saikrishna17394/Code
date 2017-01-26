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

int A[111],B[111],n,m,num;

int main() {
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);

	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>num;
		A[num]++;
	}

	cin>>m;
	for(int i=0;i<m;i++) {
		cin>>num;
		B[num]++;
	}

	int ans=0;

	for(int i=1;i<=100;i++) {
		int val=min(A[i],B[i-1]);
		ans+=val;
		A[i]-=val;
		B[i-1]-=val;

		val=min(A[i],B[i]);
		A[i]-=val;
		B[i]-=val;
		ans+=val;

		val=min(A[i],B[i+1]);
		ans+=val;
		A[i]-=val;
		B[i+1]-=val;
	}
	printf("%d\n", ans);
	return 0;
}
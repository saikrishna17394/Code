#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999
#define lim 10000001
using namespace std;

int A[lim]={0};
vector<int> v[10];

int solve(int num,int k) {
	int l=0,r=v[k].size()-1;
	if(r==-1)
		return 0;


	while(l<r) {
		int m=(l+r)/2;

		if(v[k][m+1]>num)
			r=m;
		else
			l=m+1;
	}

	if(v[k][l]<=num)
		return l+1;
	return l;
}

int main() {
	freopen("homework.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n;


	int ans=0;

	for(int i=2;i<lim;i++) {
		if(A[i]==0) {
			for(int j=i;j<lim;j+=i) {
				A[j]++;
			}
		}
	}

	for(int i=2;i<lim;i++)
		v[A[i]].push_back(i);

	cin>>t;

	for(int a=1;a<=t;a++) {

		printf("Case #%d: ",a);
		
		int x,y,k;

		cin>>x>>y>>k;

		if(k>9) {
			printf("0\n");
			continue;
		}
		
		int ans=solve(y,k);
		
		ans-=solve(x-1,k);
		
		printf("%d\n", ans);
	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 200010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n, m, A[lim];

int main(){ 
	// cin.sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		scanf("%d",&A[i]);


	int ans = 0;

	printf("%d\n", ans);
	for(int i = 0; i < n; i++)
		printf("%d ",A[i]);
	printf("\n");



	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,m;
int A[100000];

int main() {
	cin>>n>>m;

	for(int i=0;i<m;i++)
		scanf("%d",&A[i]);

	sort(A,A+m);

	int ans=0;

	ans=max(n-1-A[m-1],A[0]);

	for(int i=0;i<(m-1);i++) {
		ans=max(ans,(A[i+1]-A[i])/2);
	}


	printf("%d\n", ans);
	return 0;
}
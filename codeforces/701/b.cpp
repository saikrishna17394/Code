#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

lli n,m;
int r[lim],c[lim];

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n>>m;

	int ro=n,co=n;
	lli ans=n*n;

	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		if(r[a]==0) {
			r[a]=1;
			ans-=co;
			ro--;
		}
		if(c[b]==0) {
			c[b]=1;
			ans-=ro;
			co--;
		}
		cout<<ans<<" ";
	}
	printf("\n");

	return 0;
}
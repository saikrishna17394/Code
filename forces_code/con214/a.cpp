#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 99999999
typedef long long int lli;

int main() {
	int A[4][2][2],n,a=99999999,b=99999999,val,val1;
	cin>>n;
	for(int i=0;i<4;i++) {
		for(int j=0;j<2;j++) {
			cin>>A[i][j][0];
			cin>>A[i][j][1];
			a=min(a,A[i][j][0]);
			b=min(b,A[i][j][1]);
		}
	}

	int ans=inf,ind,kri;
	ans=2*ans;
	for(int i=0;i<4;i++) {
		val=99999999;
		val1=99999999;
		if(A[i][0][0]==a)
			val=min(val,a);
		if(A[i][0][1]==b)
			val=min(val,b);

		if(A[i][1][0]==a)
			val1=min(val1,a);
		if(A[i][1][1]==b)
			val1=min(val1,b);

		// cout<<val<<" "<<val1<<endl;

		if(val!=inf && val1!=inf) {
			if(ans>(val+val1)) {
				ind=i+1;
				ans=val+val1;
				kri=val;
			}
		}
		// cout<<ans<<endl;
	}

	if(ans<=n)
		printf("%d %d %d\n",ind,kri,n-kri);
	else
		printf("-1\n");
	return 0;
}
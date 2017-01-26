#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


ii A[3];
char B[3]={'A','B','C'};
char ans[200][200];

int main(){ 
	// cin.sync_with_stdio(false);
	
	int val=0;
	for(int i=0;i<3;i++) {
		cin>>A[i].first>>A[i].second;
		val+=A[i].first*A[i].second;
	}

	int k=sqrt(val);

	if(k*k!=val) {
		printf("-1\n");
		return 0;
	}

	for(int i=0;i<3;i++) {
		if(A[i].second==k)
			swap(A[i].first,A[i].second);
		if(A[i].first==k) {
			swap(A[0],A[i]);
			swap(B[0],B[i]);
		}
	}

	if(A[0].first!=k) {
		printf("-1\n");
		return 0;
	}

	if(A[1].first==k && A[2].first==k) {
		for(int i=0;i<k;i++) {
			for(int j=0;j<k;j++) {
				if(j<A[0].second)
					ans[i][j]=B[0];
				else if(j<(A[0].second+A[1].second))
					ans[i][j]=B[1];
				else 
					ans[i][j]=B[2];
			}
		}
	}
	else {
		if(A[1].first==(k-A[0].second))
			swap(A[1].first,A[1].second);
		if(A[2].first==(k-A[0].second))
			swap(A[2].first,A[2].second);

		if( !( A[1].second==(k-A[0].second) && A[2].second==(k-A[0].second) )) {
			printf("-1\n");
			return 0;
		}

		if((A[1].first+A[2].first)!=k) {
			printf("-1\n");
			return 0;
		}

		for(int i=0;i<k;i++) {
			for(int j=0;j<A[0].second;j++)
				ans[i][j]=B[0];
			for(int j=A[0].second;j<k;j++) {
				if(i<A[1].first)
					ans[i][j]=B[1];
				else
					ans[i][j]=B[2];
			}
		}
	}

	cout<<k<<endl;

	for(int i=0;i<k;i++) {
		for(int j=0;j<k;j++) {
			printf("%c",ans[i][j]);	
		}
		printf("\n");
	}

	return 0;
}
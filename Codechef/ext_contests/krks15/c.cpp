#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int t;
int n;
int A[lim];
int B[lim];
int ans[lim];

int main(){ 
	cin>>t;

	while(t--) {
		cin>>n;

		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);

		// printf("bro\n");
		ans[n-1]=0;

		int idx=0;
		B[idx++]=A[n-1];

		for(int i=n-2;i>=0;i--) {
			ans[i]=idx;

			while(idx>0) {
				if(A[i]>B[idx-1])
					idx--;
				else
					break;
			}
			B[idx++]=A[i];
		}

		for(int i=0;i<n;i++) {
			if(i>0)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}

	return 0;
}
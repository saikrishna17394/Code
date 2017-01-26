#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


int n,A[300];
string s[300];

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i];
	}

	for(int i=0;i<n;i++)
		cin>>s[i];


	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) {
				if(s[i][k]=='1' && s[k][j]=='1')
					s[i][j]='1';
			}

	
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if(A[j]<A[i] && s[i][j]=='1')
				swap(A[i],A[j]);
		}
	}

	for(int i=0;i<n;i++) {
		if(i>0)
			printf(" ");
		printf("%d",A[i] );
	}
	printf("\n");
	return 0;
}
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

int n,w;
int A[200000],B[200000],C[200000];

int main() {
	cin>>n>>w;

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	for(int i=0;i<w;i++)
		scanf("%d",&B[i]);

	if(w>n) {
		printf("0\n");
		return 0;
	}

	if(w==1) {
		printf("%d\n", n);
		return 0;
	}

	int num=A[0];

	for(int i=1;i<n;i++) {
		int val=A[i]-num;
		num=A[i];
		A[i]=val;
		// cout<<A[i]<<" ";
	}
	// cout<<endl;

	num=B[0];
	for(int i=1;i<w;i++) {
		int val=B[i]-num;
		num=B[i];
		B[i]=val;
		// cout<<B[i]<<" ";
	}
	// cout<<endl;

	C[1]=0;

	for(int i=2;i<w;i++) {
		int idx=C[i-1];

		while(1) {
			if(idx==0) {
				if(B[1]==B[i])
					C[i]=1;
				else
					C[i]=0;
				break;
			}
			if(B[idx+1]==B[i]) {
				C[i]=idx+1;
				break;
			}
			else {
				idx=C[idx];
			}
		}
		// cout<<i<<" "<<idx<<" "<<C[i]<<endl;
	}

	int idx=1,ans=0;

	for(int i=1;i<n;i++) {
		// cout<<A[i]<<endl;
		if(A[i]==B[idx]) {
			idx++;
			if(idx==w) {
				ans++;
				idx=C[idx-1]+1;
				// cout<<i<<"yo "<<endl;
			}
		}
		else {
			idx=C[idx]+1;
			while(1) {
				// cout<<i
				if(idx==1) {
					if(A[i]!=B[idx])
						;
					else
						idx++;
					break;
				}
				if(A[i]==B[idx]) {
					idx++;
					break;
				}
				idx=C[idx]+1;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
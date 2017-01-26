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

int n,B[2001]={0};

ii A[2001];

int main() {
	
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i].first;
		B[A[i].first]++;
		A[i].second=i+1;
	}

	sort(A,A+n);

	int ans1=-1;
	int ans2=-1,ans3=-1;

	for(int i=1;i<=2000;i++) {
		if(B[i]>2) {
			ans1=i;
			break;
		}
		if(B[i]>1) {
			if(ans2==-1)
				ans2=i;
			else {
				ans3=i;
				break;
			}
		}
	}

	if(ans1!=-1) {
		printf("YES\n");
		for(int i=0;i<n;i++)
			printf("%d ", A[i].second);
		printf("\n");

		for(int i=0;i<n;i++) {
			if(A[i].first==ans1) {
				printf("%d %d ",A[i+1].second,A[i].second);
				i+=2;
				for(;i<n;i++) {
					if(A[i].first!=ans1) {
						i--;
						break;
					}
					printf("%d ",A[i].second );
				}
			}
			else
				printf("%d ",A[i].second );
		}
		printf("\n");

		for(int i=0;i<n;i++) {
			if(A[i].first==ans1) {
				printf("%d %d %d ",A[i].second,A[i+2].second,A[i+1].second);
				i+=3;
				for(;i<n;i++) {
					if(A[i].first!=ans1) {
						i--;
						break;
					}
					printf("%d ",A[i].second );
				}
			}
			else
				printf("%d ",A[i].second );
		}
		printf("\n");

	}
	else if(ans3!=-1) {
		printf("YES\n");
		// cout<<ans2<<" "<<ans3<<endl;

		for(int i=0;i<n;i++)
			printf("%d ", A[i].second);
		printf("\n");

		for(int i=0;i<n;i++) {
			if(A[i].first==ans2) {
				ans2=-1;
				printf("%d %d ",A[i+1].second,A[i].second );
				i++;
			}
			else
				printf("%d ",A[i].second );
		}
		printf("\n");

		for(int i=0;i<n;i++) {
			if(A[i].first==ans3) {
				ans3=-1;
				printf("%d %d",A[i+1].second,A[i].second );
				i++;
			}
			else
				printf("%d ",A[i].second );
		}
		printf("\n");

	}
	else {
		printf("NO\n");
	}
	return 0;
}
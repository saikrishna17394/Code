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

using namespace std;

int A[20][3];
int B[3];

int main() {
	freopen("new_years_resolution.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n;
	cin>>t;
	string s;

	for(int a=1;a<=t;a++) {

		for(int j=0;j<3;j++)
			cin>>B[j];
		
		cin>>n;

		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>A[i][j];

		bool ok=false;

		for(int b=1;b<(1<<n);b++) {
			int mask=b;

			int C[3];
			memset(C,0,sizeof C);

			for(int i=0;i<n;i++) {
				if(mask%2==1) {
					for(int j=0;j<3;j++)
						C[j]+=A[i][j];
				}
				mask/=2;
			}

			bool ok1=true;
			for(int j=0;j<3;j++) {
				if(C[j]!=B[j])
					ok1=false;
			}
			if(ok1)
				ok=true;
		}
		printf("Case #%d: ",a);
		if(ok)
			printf("yes\n");
		else
			printf("no\n");
	}


	return 0;
}
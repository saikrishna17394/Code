#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 300010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int t,n;
int A[101][7];


int main() {
	cin>>t;

	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			int c,x;
			cin>>c;

			for(int j=1;j<=6;j++)
				A[i][j] = 0;
			while(c--) {
				cin>>x;
				A[i][x]++;
			}
		}
	}

	return 0;
}
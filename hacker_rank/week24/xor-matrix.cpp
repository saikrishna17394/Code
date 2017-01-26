#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<double,double> ii;
typedef pair<double,int> di;

lli n,m;
lli A[lim];
lli B[lim];

int main() {
	cin>>n>>m;
	
	for(int i = 0; i < n; i++) {
		cin>>A[i];
	}

	lli val = 1;
	for(int i = 0; i < 60; i++)
		val *= 2;

	m--;
	while(m > 1) {
		if(m < (val-1)) {
			val/=2;
			continue;
		}

		lli res = 0;
		if((val/n) % 2 == 1) {
			for(int i = 0; i < n; i++)
				res ^= A[i];
		}

		for(lli i = 0; i < (val%n); i++)
			res ^= A[i];

		B[0] = res;

		for(lli i = 1; i < n; i++)
			B[i] = B[i-1] ^ A[i-1] ^ A[(i-1+val)%n]; 

		for(int i = 0; i < n; i++)
			A[i] = B[i];

		m -= val-1;
		val/= 2;
	}

	if(m == 1) {
		for(int i = 0; i < n; i++)
			B[i] = A[i] ^ A[(i+1)%n];
		for(int i = 0; i < n; i++)
			A[i] = B[i];
	}

	for(int i = 0; i < n; i++)
		printf("%lld ", A[i] );

	printf("\n");

	return 0;
}
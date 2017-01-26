#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 200010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<double,double> ii;
typedef pair<double,int> di;

int n,d;
int A[lim];
int B[201];

// returns twice the median
int find_median() {
	
	if(d%2 == 1) {
		int val = 0;
		for(int i = 0; i <= 200; i++) {
			val += B[i];
			if(val > d/2)
				return 2*i;
		}
	}

	int val = 0;
	bool ok = false;
	int ret = 0;

	for(int i = 0; i <= 200; i++) {
		if(B[i] > 0 && ok) {
			ret += i;
			return ret;
		}
		val += B[i];
		if(val >= d/2) {
			if(val >= (d/2 + 1))
				return 2*i;
			ok = true;
			ret = i;
		}
	}

	return -1;
}

int main() {
	cin >> n >> d;

	for(int i = 0; i < n; i++) {
		cin>>A[i];
	}

	for(int i = 0; i < d; i++) {
		B[A[i]]++;
	}

	int ans = 0;

	for(int i = d; i < n; i++) {

		int md = find_median();

		if(A[i] >= md)
			ans++;

		B[A[i-d]]--;
		B[A[i]]++;
	}

	cout << ans << endl;

	return 0;
}
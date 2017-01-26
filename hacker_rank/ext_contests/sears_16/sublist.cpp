#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,int> di;

lli n;
map<lli,lli> m;

int main() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		lli num;
		cin >> num;
		m[num] ++;
	}

	lli ans = 1;

	for(map<lli,lli>::iterator it = m.begin(); it != m.end(); it++) {
		lli num = 1;
		
		lli val = 1;
		val = (val*n)%mod;
		val = ((lli)3 * val)%mod;
		num += val;
		
		val = (val*n)%mod;
		num += val;
		num %= mod;

		ans = (ans * num)%mod;
	}

	lli cur = 1;
	for(map<lli,lli>::iterator it = m.begin(); it != m.end(); it++) {
		lli num = 1;
		
		lli val = 1;
		val = (val*n)%mod;
		val = ((lli)3 * val)%mod;
		num += val;
		
		val = (n*n)%mod;
		val *= (lli) 2;
		num += val;
		num %= mod;

		cur = (cur * num)%mod;
	}

	ans = (ans + mod - cur) % mod;

	cur = 1;
	for(map<lli,lli>::iterator it = m.begin(); it != m.end(); it++) {
		lli num = 1;
		
		lli val = 1;
		val = (val*n)%mod;
		val = ((lli)3 * val)%mod;
		num += val;
		
		val = (n*n)%mod;
		num += val;
		num %= mod;

		cur = (cur * num)%mod;
	}

	ans = (ans + cur) % mod;

	cur = 1;
	for(map<lli,lli>::iterator it = m.begin(); it != m.end(); it++) {
		lli num = 1;
		
		lli val = 1;
		val = (val*n)%mod;
		val = ((lli)3 * val)%mod;
		num += val;
		
		num %= mod;

		cur = (cur * num)%mod;
	}

	ans = (ans + mod - cur)%mod;

	cout << ans << endl; 
	return 0;
}

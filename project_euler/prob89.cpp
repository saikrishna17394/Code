#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 10010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

map<char,int> m;

char A[] = {'I','V','X','L','C','D','M'};

int main() {
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	string s;
	int ans = 0, n;
	while(cin>>s) {
		n = s.length();
		map<char,int> m1 = m;

		for(map<char,int>::iterator it = m1.begin(); it!=m1.end(); it++)
			it->second = 0;

		for(int i=0;i<n;i++)
			m1[s[i]]++;

		for(int i=0;i<6;i++) {
			int val = m1[A[i]];
			m1[A[i+1]] += (val*m[A[i]])/m[A[i+1]];
			m1[A[i]] = ((val*m[A[i]])%m[A[i+1]])/m[A[i]];
		}

		int cur = 0;

		for(map<char,int>::iterator it = m1.begin(); it!=m1.end(); it++) {
			if(it->second == 4 && it->first!='M')
				cur += 3;
			cur += it->second;

		}

		cout<< cur <<" "<<n<<endl;
		ans += (n-cur);
		// break;

	}
	
	cout<<ans<<endl;

	return 0;
}
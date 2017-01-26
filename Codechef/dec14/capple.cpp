#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int main() {
	int t,n,num;
	cin>>t;

	while(t--) {
		cin>>n;
		set<int> s;
		while(n--) {
			cin>>num;
			s.insert(num);
		}
		cout<<s.size()<<endl;
	}

	return 0;
}
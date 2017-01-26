#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<long long int,long long int> ii;

using namespace std;
lli gcd(lli a,lli  b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

lli a,b;
int main() {
	cin>>a>>b;

	if(a<b)
		swap(a,b);

	if(a==b) {
		printf("1\n");
		return 0;
	}

	lli n=a-b;
	vector<ii> v;
	for(lli i=1;i*i<=n;i++) {
		if(n%i==0) {
			lli N=i-(b%i);

			lli val=(a+N)*(b+N);
			val/=gcd(a+N,b+N);
			v.push_back(ii(val,N));

			lli num=n/i;

			N=num-(b%num);

			val=(a+N)*(b+N);
			val/=gcd(a+N,b+N);

			v.push_back(ii(val,N));
		}
	}

	sort(v.begin(),v.end());

	cout<<v[0].second<<endl;
	return 0;
}
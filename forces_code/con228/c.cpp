#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	int n,A[100],ans,g;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A,A+n);
	multiset<int> s;
	s.insert(1);
	ans=1;

	for(int i=1;i<n;i++) {
		int val=*s.begin();
		if(A[i]>=val) {
			s.erase(s.begin());
			s.insert(val+1);
		}
		else {
			s.insert(1);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
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

int main() {
	int n,A[100],ans=1,num;

	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A,A+n);

	multiset<int> s;
	s.insert(1);

	for(int i=1;i<n;i++) {
		num=*s.begin();

		if(A[i]>=num) {
			s.erase(s.begin());
			s.insert(num+1);
		}
		else {
			ans++;
			s.insert(1);
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
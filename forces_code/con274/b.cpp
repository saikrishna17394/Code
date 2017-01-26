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

int A[100000];

set<int> s;

int main() {
	int n,l,x,y;

	cin>>n>>l>>x>>y;

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		s.insert(A[i]);
	}

	int ans=-1;

	// vector<int> val;

	set<int> s1,s2;

	bool ok=false,ok1=false;
	for(int i=0;i<n;i++) {
		int val=A[i]+x;
		int val1=A[i]+y;

		if(s.find(val)!=s.end()) {
			ok=true;
			ans=y;
		}
		if(s.find(val1)!=s.end()) {
			ok1=true;
			ans=x;
		}

		if(ok && ok1) {
			printf("0\n");
			return 0;
		}
		if(val<=l)
			s1.insert(val);
		if(val1<=l)
			s2.insert(val1);


		val=A[i]-x;
		val1=A[i]-y;

		if(s.find(val)!=s.end()) {
			ok=true;
			ans=y;
		}
		if(s.find(val1)!=s.end()) {
			ok1=true;
			ans=x;
		}

		if(ok && ok1) {
			printf("0\n");
			return 0;
		}
		if(val>=0)
			s1.insert(val);
		if(val1>=0)
			s2.insert(val1);

	}

	if(ok || ok1) {
		printf("1\n");
		printf("%d\n", ans);
		return 0;
	}

	for(set<int>::iterator it=s1.begin();it!=s1.end();it++) {
		if(s2.find(*it)!=s2.end()) {
			printf("1\n");
			printf("%d\n", *it);
			return 0;
		}
	}
	printf("2\n");
	printf("%d %d\n", x,y);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999

using namespace std;

int t,n;

int main() {
	freopen("inp", "r", stdin);
	// freopen("A-large.in", "r", stdin);
	// freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin>>t;

	for(int a=1;a<=t;a++) {

		cin>>n;
		set<pair<char,int> > s;

		for(int i = 0; i<n; i++) {
			int num;
			cin>>num;
			s.insert(make_pair(num,'A'+i));
		}

		printf("Case #%d:",a);

		while(!s.empty()) {
			int sz = s.size();

			
		}
		printf("\n");
	}




	return 0;
}
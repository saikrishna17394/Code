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

int n,A[3000],idx[3000];
set<ii> m;

int main() {
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i];
		m.insert(ii(A[i],i));
		idx[i]=A[i];
	}

	cout<<n<<endl;
	int val=0;

	while(val<n) {
		set<ii>::iterator it=m.begin();
		printf("%d %d\n", val,it->second);
		
		m.erase(ii(A[val],val));
		m.insert(ii(A[val],it->second));
		A[it->second]=A[val];
		
		m.erase(*it);

		val++;
	}

	return 0;
}
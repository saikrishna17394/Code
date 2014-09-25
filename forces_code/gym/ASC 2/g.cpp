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

int n,m,y,A[10010],B[10010];

set<ii> s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin>>n>>m>>y;

	for(int i=0;i<n;i++)
		cin>>A[i];


	int cnt=0;

	for(int i=0;i<n;i++) {
		B[i]=A[i]*m;
		B[i]/=y;

		int rem=(A[i]*m)%y;

		if(rem!=0)
			s.insert(ii(rem,i));
		cnt+=B[i];
	}

	cnt=m-cnt;


	set<ii>::reverse_iterator it=s.rbegin();

	while(cnt--) {
		B[it->second]++;
		it++;
	}

	for(int i=0;i<n;i++) {
		if(i<(n-1))
			printf("%d ",B[i]);
		else
			printf("%d\n", B[i]);
	}

	return 0;
}
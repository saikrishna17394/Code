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

int t,n;

int rev(int n) {
	int ret=0;
	while(n>0) {
		ret=ret*10;
		ret+=n%10;
		n/=10;
	}
	return ret;
}
int main() {
	cin>>t;

	while(t--) {
		cin>>n;
		printf("%d\n",rev(n));
	}

	return 0;
}
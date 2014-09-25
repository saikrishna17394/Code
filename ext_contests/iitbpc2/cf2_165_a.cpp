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
	int t,a;

	cin>>t;

	while(t--) {
		cin>>a;
		a=180-a;
		if(360%a==0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
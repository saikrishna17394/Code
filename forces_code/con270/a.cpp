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


int n;

int main() {
	cin>>n;

	if(n%2==0) {
		int x=n/2;
		if(x%2==0)
			printf("%d %d\n", n/2,n/2);
		else
			printf("%d %d\n", x+1,x-1);
	}
	else {
		printf("%d %d\n", n-9,9);
	}

	return 0;
}
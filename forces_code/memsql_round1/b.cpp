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
	int n,m;

	cin>>n>>m;

	if(n==0) {
		printf("0 1\n");
		printf("0 %d\n", m);
		printf("0 0\n");
		printf("0 %d\n", m-1);
	}
	else if(m==0) {
		printf("1 0\n" );
		printf("%d 0\n", n);
		printf("0 0\n");
		printf("%d 0\n", n-1);
	}
	else {
		printf("0 0\n");
		printf("%d %d\n", n,m);
		if(n>=m) {
			printf("0 %d\n", m);
			printf("%d 0\n", n);
		}
		else {
			printf("%d 0\n", n);
			printf("0 %d\n", m);
		}
	}

	return 0;
}
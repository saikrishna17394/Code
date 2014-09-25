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
	int n;

	cin>>n;

	if(n<4) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	if(n%2==0) {
		printf("1 * 2 = 2\n");
		printf("3 * 2 = 6\n");
		printf("6 * 4 = 24\n");

		int val=0;
		for(int i=5;i<n;i+=2) {
			printf("%d - %d = 1\n",i+1,i );
			val++;
		}

		for(int i=0;i<val;i++)
			printf("24 * 1 = 24\n");
	}
	else {
		printf("3 - 1 = 2\n");
		printf("5 - 2 = 3\n");
		printf("3 * 2 = 6\n");
		printf("6 * 4 = 24\n");		

		int val=0;
		for(int i=6;i<n;i+=2) {
			printf("%d - %d = 1\n",i+1,i );
			val++;
		}

		for(int i=0;i<val;i++)
			printf("24 * 1 = 24\n");

	}
	return 0;
}
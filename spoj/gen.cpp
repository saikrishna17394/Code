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

using namespace std;

int main() {
	printf("1\n");

	printf("40000\n");

	for(int i=0;i<40000;i++) {
		int a=rand()%10000000;
		int b=rand()%10000000;

		if(a>b) {
			swap(a,b);
		}
		a++;
		b++;

		if(a==b) {
			if(a>10)
				a--;
			else
				b++;
		}

		printf("%d %d\n",a,b );
	}


	return 0;
}
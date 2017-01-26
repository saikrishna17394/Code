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

#define mod 1008
#define inf 999999999
#define lim 1000000
using namespace std;

int main() {
	lli t=400000;
	cout<<t<<endl;
	for(int i=2;i<=5;i++) {
		for(int j=1;j<=100000;j++) {
			printf("%d %d %d\n",i,j,i );
			for(int k=1;k<=i;k++)
				printf("%d\n",k );
		}
	}
	return 0;
}
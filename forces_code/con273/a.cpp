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
	int A[5];
	int sum=0;

	for(int i=0;i<5;i++) {
		cin>>A[i];
		sum+=A[i];
	}
	if(sum%5!=0 || sum==0)
		printf("-1\n");
	else
		printf("%d\n", sum/5);
	return 0;
}
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
	int a,b;

	cin>>a>>b;

	a=min(a,b);

	if(a%2==1)
		printf("Akshat\n");
	else
		printf("Malvika\n");


	return 0;
}
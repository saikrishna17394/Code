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
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

int dp[14][7];

int solve(int idx,int rem) {
	if(idx==14) {
		if(rem==3)
			return 1;
		return 0;
	}
	int &ret=dp[idx][rem];
	if(ret!=-1)
		return ret;
	ret=0;
	ret+=solve(idx+1,(rem*10)%7);
	ret+=solve(idx+1,(rem*10+5)%7);
	return ret;
}
int main() {
	
	return 0;
}
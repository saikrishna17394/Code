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

double power(double n,int k) {
	double ret=1.0;

	while(k) {
		if(k%2==1)
			ret=ret*n;
		n=n*n;
		k/=2;
	}
	return ret;
}


int m,n;

int main() {
	cin>>m>>n;

	double ans;
	ans=m;

	for(int i=m-1;i>=1;i--) {
		double val=i;
		val/=(double)m;
		val=power(val,n);

		if(val<1e-14)
			break;
		ans-=val;
	}

	printf("%.8f\n", ans);
	return 0;
}
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

lli n;

int main() {
	
	cin>>n;

	long long int flr=0,ans=0,val=0,num=1;

	if(n%3==2) {
		n-=2;
	}
	else if(n%3==1) {
		n-=4;
		flr=1;
		val=1;
		num=2;
	}
	else {
		n-=6;
		flr=2;
		val=3;
		num=3;
	}

	n/=3;

	while(n>=val) {
		ans++;
		val+=3*num+3;
		num+=3;
		n-=2;
	}

	cout<<ans<<endl;
	return 0;
}
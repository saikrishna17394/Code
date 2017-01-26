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

int t,w,r,m,s;

int main() {
	cin>>t;

	for(int a=1;a<=t;a++) {
		cin>>w>>r>>m>>s;
		printf("Case #%d:\n",a );

		if(m>=10)
			printf("NOTHING\n");
		else if(w<35 || r<40)
			printf("EMERGENCY\n");
		else if(m<10 && r>60)
			printf("NIGHTMARE\n");
		else if(s>28800)
			printf("WAKE-UP\n");
		else
			printf("NOTHING\n");
	}


	return 0;
}
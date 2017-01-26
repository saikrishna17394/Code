#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

bool check(int n) {
	for(int i=2;i*i<=n;i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

int main(){ 
	int n;
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n<=3 || check(n)) {
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%d\n", i);
	}
	else {
		printf("NO\n");
	}
	return 0;
}
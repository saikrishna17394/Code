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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int t,n;
	cin>>t;

	double e=exp(1.0);

	while(t--) {
		scanf("%d",&n);

		if(n==0) {
			printf("1\n");
			continue;
		}

		// cout<<e<<endl;

		double ans=log(e);
		ans/=log(10);

		// cout<<ans<<endl;

		ans*=(double)n;

		int ans1=ans;

		cout<<ans1+1<<endl;
	}

	return 0;
}
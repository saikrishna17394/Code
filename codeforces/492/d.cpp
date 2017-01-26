#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

lli n,x,y,a;

int main(){ 
	cin.sync_with_stdio(false);
	
	cin>>n>>x>>y;

	while(n--) {
		cin>>a;

		lli l=1,r=(lli)1e16;

		while(l<r) {
			lli m=(l+r)/2;

			lli val=m/x+m/y;
			if(val<a)
				l=m+1;
			else
				r=m;
		}
		if(l%y==0) {
			if(l%x==0)
				printf("Both\n");
			else
				printf("Vanya\n");
		}
		else {
			printf("Vova\n");
		}
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int main(){ 
	int t,n;

	cin>>t;

	while(t--) {
		cin>>n;
		int n1=n;

		int val=-1;

		for(int i=2;i*i<=n;i++) {
			while(n%i==0) {
				val=i;
				n/=i;
			}
		}

		if(val==-1) {
			printf("1\n");
		}
		else {
			val=max(val,n);
			printf("%d\n", n1/val);
		}

	}

	return 0;
}
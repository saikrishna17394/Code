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


lli t,n,k,d1,d2;
lli a,b,c;

int main() {
	cin>>t;

	while(t--) {
		cin>>n>>k>>d1>>d2;

		bool ok=false;

		lli num=k+d1+d2;

		if(num%3==0) {
			b=num/3;
			a=b-d1;
			c=b-d2;

			if(a>=0 && b>=0 && c>=0) {
				num=n-k+a+b+c;
				if(num%3==0) {
					num/=3;
					if(num>=a && num>=b && num>=c)
						ok=true;
				}
			}
		}

		num=k+d1-d2;

		if(num%3==0) {
			b=num/3;
			a=b-d1;
			c=b+d2;

			if(a>=0 && b>=0 && c>=0) {
				num=n-k+a+b+c;
				if(num%3==0) {
					num/=3;
					if(num>=a && num>=b && num>=c)
						ok=true;
				}
			}

		}


		num=k-d1+d2;

		if(num%3==0) {
			b=num/3;
			a=b+d1;
			c=b-d2;

			if(a>=0 && b>=0 && c>=0) {
				num=n-k+a+b+c;
				if(num%3==0) {
					num/=3;
					if(num>=a && num>=b && num>=c)
						ok=true;
				}
			}

		}

		num=k-d1-d2;

		if(num%3==0) {
			b=num/3;
			a=b+d1;
			c=b+d2;

			if(a>=0 && b>=0 && c>=0) {
				num=n-k+a+b+c;
				if(num%3==0) {
					num/=3;
					if(num>=a && num>=b && num>=c)
						ok=true;
				}
			}

		}

		if(ok)
			printf("yes\n");
		else
			printf("no\n");

	}

	return 0;
}
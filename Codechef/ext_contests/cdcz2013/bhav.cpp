#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main() {
	int t,s,n,c,val;
	cin>>t;


	while(t--) {
		cin>>s;
		cin>>n;
		cin>>c;

		if((n+2*c)<s)
			printf("NO\n");
		else {
			if(s<n)
				printf("YES 0\n");
			else {
				val=(s-n)/2;
				if((s-n)&1)
					val++;
				printf("YES %d\n", val);
			}
		}

	}


	return 0;
}
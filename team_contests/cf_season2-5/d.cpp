#include <bits/stdc++.h>
#define lli long long int

using namespace std;

set<lli> m;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	lli a,b,c;
	cin>>a>>b>>c;
	m.insert(1);
	
	lli x=1;

	for(int i=1;i<20000000;i+=2000000) {
		m.clear();
		m.insert(1);
		for(int j=0;j<2000000;j++) {
			x=(a*x+(x%b))%c;
			if(m.find(x)!=m.end()) {
				printf("%d\n",i+j);
				return 0;
			}
			m.insert(x);
		}
		lli y=x;
		for(int j=i+2000000;j<=20000000;j++) {
			y=(a*y+(y%b))%c;
			if(m.find(y)!=m.end()) {
				printf("%d\n",j);
				return 0;
			}
		}
	}
	printf("-1\n");

	return 0;
}

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
	lli t,n,s,e,x,y;
	cin>>t;
	
	while(t--) {
		cin>>s>>e;
		cin>>n;
		
		bool ok=true;		
		for(int i=0;i<n;i++) {
			cin>>x>>y;
			if(x>=e || y<=s)
				continue;
			ok=false;
			//break;
		}
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
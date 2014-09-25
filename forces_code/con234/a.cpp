#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;


int main() {
	int t,A[13],ans;
	cin>>t;

	string s;

	while(t--) {
		cin>>s;

		memset(A,0,sizeof A);
		ans=0;
		for(int i=1;i<=12;i++) {
			if(12%i!=0)
				continue;
			int num=12/i;
			int idx=0;

			bool ok=true;
			for(int j=0;j<num;j++) {
				ok=true;
				for(int k=0;k<i;k++) {
					if(s[k*num+j]!='X')
						ok=false;
				}
				if(ok)
					break;
			}

			if(ok) {
				A[i]=1;
				ans++;
			}

		}

		printf("%d",ans);

		for(int i=1;i<=12;i++) {
			if(A[i]) {
				printf(" %dx%d",i,12/i );
			}
		}
		printf("\n");
	
	}


	return 0;
}
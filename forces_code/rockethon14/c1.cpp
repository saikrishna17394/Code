#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 999999999
typedef long long int lli;
typedef pair<int,int> ii;

int main() {
	int n,k,p[20],e[20],A[20];
	scanf("%d %d",&n,&k);

	for(int i=0;i<n;i++) {
		scanf("%d %d",&p[i],&e[i]);
	}

	int num=1<<n;
	int ans=inf;
	for(int j=0;j<num;j++) {
		int mask=j;
		int pts=0,val=0;
		for(int i=0;i<n;i++) {
			if(mask&1) {
				pts++;
				val+=e[i];
			}
			mask>>=1;
		}
		int bet=0;
		mask=j;
		for(int i=0;i<n;i++) {
			if(mask&1) {
				if(pts<p[i])
					bet++;
			}
			else {
				if(pts<=(p[i]+1))
					bet++;
			}
			mask>>=1;
		}
		// cout<<j<<" "
		if(bet<k)
			ans=min(ans,val);
	}
	if(ans==inf)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
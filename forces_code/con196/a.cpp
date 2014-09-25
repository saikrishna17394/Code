#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n,m,A[50],ans=9999999;

	scanf("%d %d",&n,&m);

	for(int i=0;i<m;i++)
		scanf("%d",&A[i]);

	sort(A,A+m);

	for(int i=0;i<=(m-n);i++)
		ans=min(ans,A[i+n-1]-A[i]);

	printf("%d\n",ans);

	return 0;
}
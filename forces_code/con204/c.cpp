#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int A[4000],x,y;
	int n;

	scanf("%d",&n);

	int cnt=0,sum=0;
	for(int i=0;i<2*n;i++) {
		scanf("%d.%d",&x,&y);
		if(y==0)
			cnt++;
		sum+=y;
	}
	sum-=(n*1000);
	int ans=1<<30;

	for(int i=0;i<=min(cnt,n);i++)
		ans=min(ans,abs(sum+i*1000));

	printf("%d.",ans/1000);
	ans%=1000;
	if(ans<10)
		printf("00%d\n", ans);
	else if(ans<100)
		printf("0%d\n", ans);
	else
		printf("%d\n", ans);

	return 0;
}
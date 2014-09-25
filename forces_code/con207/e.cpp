#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n,num,A[5]={0},ans;
	scanf("%d",&n);

	for(int i=0;i<n;i++) {
		scanf("%d",&num);
		A[num]++;
	}

	if(A[1]<=A[2]) {
		A[3]+=A[1];
		ans=A[1];
		A[2]-=A[1];
		A[1]=0;
		if(A[2]<=A[4]) {
			ans+=A[2];
			printf("%d\n",ans);
			return 0;
		}
		printf("-1\n");
	}
	else {
		ans=A[2];
		A[3]+=A[2];
		A[1]-=A[2];
		A[2]=0;

		if(A[1]<=A[3]) {
			ans+=A[1];
			printf("%d\n",ans );
			return 0;
		}
	
		printf("-1\n");
	}
	return 0;
}
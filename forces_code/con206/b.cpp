#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lli;

int main() {
	int c1,c2,c3,c4,n,m,A[1000],B[1000],ans=0,ans1=0,ans_f;

	scanf("%d %d %d %d",&c1,&c2,&c3,&c4);

	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		ans+=min(A[i]*c1,c2);
	}

	for(int i=0;i<m;i++) {
		scanf("%d",&B[i]);
		ans1+=min(B[i]*c1,c2);
	}

	ans_f=min(2*c3,c4);
	ans_f=min(ans_f,ans+c3);
	ans_f=min(ans_f,ans1+c3);
	ans_f=min(ans_f,ans1+ans);

	printf("%d\n", ans_f);
	return 0;
}
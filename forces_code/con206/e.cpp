#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
int n,A[300000],k;

int find(int a,int b) {
	// cout<<a<<" "<<b<<endl;
	if(a==b)
		return a;

	int mid=(a+b)/2;
	mid++;
	// cout<<mid<<endl;
	for(int i=0;i<n;i++) {
		if((A[i]/mid)>0 && (A[i]%mid)<=k)
			;
		else
			return find(a,mid-1);
	}
	// cout<<"man\n";
	return find(mid,b);
}

int main() {
	int small,big;
	scanf("%d %d",&n,&k);

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	small=A[0];
	big=A[0];

	for(int i=1;i<n;i++) {
		small=min(small,A[i]);
		big=max(big,A[i]);
	}

	if((big-small)<=k)
		printf("%d\n",small);
	else
		printf("%d\n", find(1,1000000));
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;

bool check(ii a,ii b) {
	if(a.first>b.first)
		swap(a,b);

	if(b.first>=a.second)
		return false;

	if(b.second<=a.second)
		return false;
	return true;
}
int main() {
	int n,num,ind,prev;
	ii A[1000];
	ind=0;
	scanf("%d",&n);
	scanf("%d",&num);
	prev=num;


	for(int i=1;i<n;i++) {
		scanf("%d",&num);
		A[ind++]=ii(min(num,prev),max(prev,num));

		for(int j=0;j<(ind-1);j++) {
			if(check(A[j],A[ind-1])) {
				cout<<A[j].first<<" "<<A[j].second<<endl;
				cout<<A[ind-1].first<<" "<<A[ind-1].second<<endl;
				printf("yes\n");
				return 0;
			}
		}
		prev=num;
	}

	printf("no\n");
	return 0;
}
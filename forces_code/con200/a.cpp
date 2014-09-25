#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n,rec,num,ans;

	scanf("%d",&n);
	ans=1;
	scanf("%d",&rec);

	for(int i=1;i<n;i++) {
		scanf("%d",&num);
		if(num!=rec) {
			ans++;
		}
		rec=num;
	}


	printf("%d\n",ans);

	return 0;
}
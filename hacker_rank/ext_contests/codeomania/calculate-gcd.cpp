#include <bits/stdc++.h>
int main() {
	int t,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b),
		printf("%d\n",std::__gcd(a,b) );
	}
}
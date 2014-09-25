#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef pair<char,int> ii;

int main() {
	int t,n,c,ans;

	scanf("%d",&t);

	while(t--) {
		scanf("%d %d",&n,&c);
		ans=n/c;
		if(n%c)
			ans++;
		ans--;
		printf("%d\n", ans);
	}


	return 0;
}
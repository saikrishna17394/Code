#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main() {
	int n,m,a,b;
	list<int> l[100001];

	scanf("%d %d",&n,&m);

	for(int i=0;i<m;i++) {
		scanf("%d %d",&a,&b);
		l[a].push_back(b);
		l[b].push_back(a);
	}

	

	return 0;
}
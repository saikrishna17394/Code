#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;


int main() {
	int n,m,x,y,z,p,a,b;

	scanf("%d %d %d %d %d %d",&n,&m,&x,&y,&z,&p);

	x=x%4;
	y=y%2;
	z=-z%4;
	if(z<0)
		z+=4;

	while(p--) {
		scanf("%d %d",&a,&b);

		int c,d;
		for(int i=0;i<x;i++) {
			c=b;
			d=n-a+1;
			a=c;
			b=d;
			swap(n,m);
		}

		if(y) {
			a=n-a+1;
		}

		for(int i=0;i<z;i++) {
			c=b;
			d=n-a+1;
			a=c;
			b=d;
			swap(n,m);
		}
		printf("%d %d\n", a,b);
	}

	return 0;
}
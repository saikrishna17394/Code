#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 99999999
typedef long long int lli;

int main() {
	int x1,y1,x2,y2,ans;

	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

	if(x1==x2 || y1==y2)
		printf("1 ");
	else
		printf("2 ");

	if(((x1+y1)%2)!=((x2+y2)%2))
		printf("0 ");
	else if(abs(x1-x2)==abs(y1-y2))
		printf("1 ");
	else
		printf("2 ");

	printf("%d\n", max(abs(x1-x2),abs(y1-y2)));

	return 0;
}
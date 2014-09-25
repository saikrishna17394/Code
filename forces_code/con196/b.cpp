#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main() {
	int a,b,c,d,p,q,num;

	scanf("%d %d %d %d",&a,&b,&c,&d);

	if(c*b<=a*d) {
		p=d*a-c*b;
		q=a*d;
		num=gcd(p,q);
		p/=num;
		q/=num;
		printf("%d/%d\n",p,q);
	}
	else {
		p=b*c-a*d;
		q=b*c;
		num=gcd(p,q);
		p/=num;
		q/=num;
		printf("%d/%d\n",p,q);

	}

	return 0;
}

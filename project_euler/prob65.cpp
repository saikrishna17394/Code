#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define lim 1000200
using namespace std;

lli gcd (lli a, lli b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main() {
	lli A[103];

	A[0]=2;
	for(int i=1;i<=100;i+=3) {
		A[i]=1;
		A[i+1]=2*(i+2)/3;
		A[i+2]=1;
	}
	lli num,den,g;

	den=1;
	num=A[99];

	for(int i=98;i>=0;i--) {
		swap(num,den);
		num=A[i]*den+num;
		g=gcd(num,den);
		num/=g;
		den/=g;
		cout<<i<<" "<<num<<" "<<den<<endl;
	}
	cout<<num<<" "<<den<<endl;
	return 0;
}
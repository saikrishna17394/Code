#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;

int main() {
	int n;
	ii A[100000],B[100000],C[100000],D[100000];
	int a=0,b=0,c=0,d=0,a1,a2,ans=0;

	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d %d",&a1,&a2);
		ans+=6;

		if(a1==0 || a2==0)
			ans-=2;
		if(a1>=0 && a2>=0)
			A[a++]=ii(a1,a2);
		else if(a1>=0 && a2<0)
			B[b++]=ii(a1,-a2);
		else if(a1<0 && a2>=0)
			C[c++]=ii(-a1,a2);
		else
			D[d++]=ii(-a1,-a2);
	}
	sort(A,A+a);
	sort(B,B+b);
	sort(C,C+c);
	sort(D,D+d);

	printf("%d\n", ans);

	for(int i=0;i<a;i++) {
		if(A[i].x)
			printf("1 %d R\n",A[i].x);
		if(A[i].y)
			printf("1 %d U\n",A[i].y);
		printf("2\n");
		if(A[i].x)
			printf("1 %d L\n",A[i].x);
		if(A[i].y)
			printf("1 %d D\n",A[i].y );
		printf("3\n");
	}
	for(int i=0;i<b;i++) {
		if(B[i].x)
			printf("1 %d R\n",B[i].x);
		if(B[i].y)
			printf("1 %d D\n",B[i].y);
		printf("2\n");
		if(B[i].x)
			printf("1 %d L\n",B[i].x);
		if(B[i].y)
			printf("1 %d U\n",B[i].y );
		printf("3\n");
	}
	for(int i=0;i<c;i++) {
		if(C[i].x)
			printf("1 %d L\n",C[i].x);
		if(C[i].y)
			printf("1 %d U\n",C[i].y);
		printf("2\n");
		if(C[i].x)
			printf("1 %d R\n",C[i].x);
		if(C[i].y)
			printf("1 %d D\n",C[i].y );
		printf("3\n");
		
	}
	for(int i=0;i<d;i++) {
		if(D[i].x)
			printf("1 %d L\n",D[i].x);
		if(D[i].y)
			printf("1 %d D\n",D[i].y);
		printf("2\n");
		if(D[i].x)
			printf("1 %d R\n",D[i].x);
		if(D[i].y)
			printf("1 %d U\n",D[i].y );
		printf("3\n");
	}

	return 0;
}
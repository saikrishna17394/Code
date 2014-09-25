#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

int main() {
	int A[]={1,6,8,9},B[7];
	do {
		int num=0;
		for(int i=0;i<4;i++)
			num=num*10+A[i];
		B[num%7]=num;
	}	while(next_permutation(A,A+4));

	int C[10]={0},len;
	string s;
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
		C[s[i]-'0']++;
	C[1]--;
	C[6]--;
	C[8]--;
	C[9]--;
	int num=0;

	if(C[0]+4==len) {
		printf("%d",B[0]);
		for(int i=0;i<C[0];i++)
			printf("0");
		printf("\n");
		return 0;
	}
	for(int i=9;i>=0;i--) {
		while(C[i]) {
			num=num*10+i;
			num%=7;
			printf("%d",i);
			C[i]--;
		}
	}
	num=num*10000;
	num%=7;
	printf("%d\n",B[(7-num)%7]);
	return 0;
}
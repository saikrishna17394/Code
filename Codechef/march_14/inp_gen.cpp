#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000009
#define inf 999999999
#define MAXN 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	cout<<"100000 100\n";

	for(int i=0;i<100000;i++) {
		int num=rand()%100000;
		printf("%d\n",num+1);
	}
	printf("\n");

	for(int j=0;j<100;j++) {
		int num=rand()%100000;
		int num1=rand()%100000;
		int num2=rand()%100000;
		int a=max(num1,num2);
		int b=min(num1,num2);
		printf("%d %d %d\n",num,b+1,a+1);
	}
	return 0;
}
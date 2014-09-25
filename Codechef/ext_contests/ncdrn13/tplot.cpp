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
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999

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
	int A[46]={0},num,val,val1;

	for(int i=0;i<6;i++) {
		inp(num);
		A[num]=1;
	}
	inp(num);
	A[num]=10;

	for(int j=0;j<5;j++) {
		val=0;
		for(int i=0;i<6;i++) {
			inp(num);
			val+=A[num];
		}
		val1=val;
		val=val%10;

		if(val1==15)
			printf("Second Parking slot\n");
		else if(val==6)
			printf("First Parking slot\n");
		else if(val==5)
			printf("Third Parking slot\n");
		else if(val==4)
			printf("Fourth Parking slot\n");
		else if(val==3)
			printf("Fifth Parking slot\n");
		else
			printf("No Parking slot\n");
	}

	return 0;
}
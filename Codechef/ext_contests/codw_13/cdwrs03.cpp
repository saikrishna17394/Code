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
int A[1000000],sz=0;

int find(int i,int j,int val) {
	int mid;

	while(i<j) {
		mid=(i+j)/2;
		if(A[mid]<val)
			i=mid+1;
		else
			j=mid;
	}
	return i;
}
int main() {
	int n,num,big;

	inp(n);
	inp(num);

	A[sz++]=num;

	for(int i=1;i<n;i++) {
		inp(num);

		if(num>A[sz-1])
			A[sz++]=num;
		else {
			int idx=find(0,sz-1,num);
			A[idx]=num;
		}
	}

	printf("%d\n",sz);

	return 0;
}
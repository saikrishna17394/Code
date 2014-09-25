#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int n,num,val,ind=0;
	int A[100000];

	lli ans=0;

	inp(n);

	while(n--) {
		inp(num);
		if(num<0)
			A[ind++]=num;
	}
	inp(val);

	sort(A,A+ind);

	if(val<=ind) {
		ans=(lli)val*(lli)A[val-1];
		ans=-ans;

		for(int i=0;i<min(ind,val-1);i++)
			ans=ans+(lli)(A[val-1]-A[i]);
	}

	else {
		for(int i=0;i<min(ind,val-1);i++)
			ans=ans-(lli)A[i];

	}

	printf("%lld\n",ans);

	return 0;
}


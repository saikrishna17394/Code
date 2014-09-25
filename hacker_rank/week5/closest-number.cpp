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

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int main() {
	int t,x,a,b,num;

	inp(t);

	while(t--) {
		inp(a);
		inp(b);
		inp(x);

		if(a==1)
			num=1;
		else if(b==0)
			num=1;
		else if(b<0)
			num=0;
		else {
			num=1;
			for(int i=0;i<b;i++)
				num*=a;
		}

		int rem=num%x;

		if(rem<=(x-rem))
			num-=rem;
		else
			num+=(x-rem);

		printf("%d\n", num);

	}

	return 0;
}
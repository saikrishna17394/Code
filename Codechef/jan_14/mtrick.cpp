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
#define lim 100010
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,A[1000],a,b,c;
string s;

lli mul(lli num,lli k) {
	lli ret=0;


	while(k) {
		if(k&1)
			ret=(ret+num)%c;
		k>>=1;
		num=(num*2)%c;
	}
	return ret;
}

lli pro,add;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(int i=0;i<n;i++)
			inp(A[i]);
		inp(a);
		inp(b);
		inp(c);
		cin>>s;
		a%=c;
		b%=c;

		add=0;
		pro=1;

		int l=0,r=n-1,l1,l2;
		for(int i=0;i<n;i++) {
			if(s[i]=='R') {
				swap(l,r);
				// int val=n-i;
				// val/=2;
				// for(int j=i;j<val;j++)
				// 	swap(A[j],A[n-j+i-1]);
			}
			else if(s[i]=='A') {
				add=(add+a)%c;
			}
			else {
				pro=mul(pro,b);
				add=mul(add,b);
			}
			A[l]=mul(A[l],pro);
			A[l]=(A[l]+add)%c;
			printf("%lld ",A[l] );
			if(l<=r)
				l++;
			else
				l--;

		}
		printf("\n");
	}

	return 0;
}
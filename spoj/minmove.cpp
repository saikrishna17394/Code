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
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int len=0,a,b,l;
	char A[100000],ch;
	ch=getchar_unlocked();

	while(ch!='\n') {
		A[len++]=ch;
		ch=getchar_unlocked();
	}

	a=0;
	b=1;

	while(b<len) {
		// cout<<a<<" "<<b<<endl;
		l=0;
		
		while(a+l<len) {
			if(A[a+l]==A[(b+l)%len])
				l++;
			else
				break;
		}
		if(a+l==len)
			break;
		if(A[(a+l)%len]<A[(b+l)%len]) {
			b=b+l+1;
		}
		else {
			a=max(b,a+l+1); // idi ganuka a=b ante chalu tiime limit exceeded
							//phat ante
			b=a+1;
		}
	}
	printf("%d\n",a);
	return 0;
}
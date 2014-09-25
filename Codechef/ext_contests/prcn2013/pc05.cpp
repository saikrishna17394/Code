#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int primes []={2,3,5,7,11,13,17,19,23,29,31};

int sum(int n) {
	int res=0;

	while(n!=0) {
		res+=n%10;
		n/=10;
	}
	return res;
}

int main() {
	int t,a,b;
	inp(t);
	int A[10001];
	int p[40]={0};
	for(int i=0;i<11;i++)
		p[primes[i]]=1;

	A[0]=0;
	for(int i=1;i<10001;i++) {
		if(p[sum(i)]==1)
			A[i]=A[i-1]+1;
		else
			A[i]=A[i-1];
	}
	//cout<<A[11]<<" "<<A[21]<<endl;
	while(t--) {
		inp(a);
		inp(b);
		printf("%d\n",A[b]-A[a-1]);
	}
	return 0;
}
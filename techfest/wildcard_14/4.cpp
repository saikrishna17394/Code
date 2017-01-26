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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000004
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
// int A[10001][2301];
bool check(lli n) {
	lli k=sqrt(n);

	lli i=max((lli)1,k-10);
	for(;i<(k+10);i++)
		if(i*i==n)
			return true;
	return false;
}
lli fac[21];
int main() {
	lli num=1;
	fac[1]=1;
	for(lli i=2;i<11;i++) {
		num*=i;
		fac[i]=num;
		cout<<i<<" "<<fac[i]*fac[i]<<endl;
	}

	// for(int i=1;i<)
	for(int i=1;i<11;i++) {
		for(int j=i;j<11;j++) {
			lli num=fac[j]*fac[i];
			num-=fac[j];
			num-=fac[i];
			if(check(num))
				cout<<i<<" "<<j<<" "<<num<<endl;
		}
	}
	return 0;
}
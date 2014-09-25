#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define x getchar_unlocked()
#define mod 10000000000
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
	int ans=0;
	for(int i=3;i<=1000;i++) {
		if(i&1) {
			ans+=i*(i-1);
		}
		else
			ans+=i*(i-2);
	}
	cout<<ans<<endl;
	return 0;
}
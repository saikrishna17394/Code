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
	int a,n;

	double max=1,ans,val;

	for(int i=1;i<=1000;i++) {
		inp(a);
		inp(n);

		val=log(a);
		val=val*(double)n;

		if(val>max) {
			max=val;
			ans=i;
		}
	}

	cout<<ans<<endl;

	return 0;

}
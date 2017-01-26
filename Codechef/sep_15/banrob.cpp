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

#define mod 1000000009
#define inf 1999999999
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

double pow1(double p,int n) {
	double ret=1.0;

	while(n>0) {
		if(n%2==1) {
			ret*=p;
		}
		p*=p;
		n/=2;
	}
	return ret;
}


double solve(int n,double p) {
	if(n==1)
		return 1e9;
	if(n==2)
		return (1.0+p)*1e9;
	double ret=solve(n/2+1,p*p);

	ret*=(1.0+p);
	if(n%2==0) {
		ret-=pow1(p,n+1)*1e9;
	}
	return ret;
}
int t,m;
double p;

int main() {
	inp(t);

	while(t--) {
		inp(m);
		cin>>p;

		double ans;

		m--;

		if(m==0) {
			ans=1e9;
		}
		else if(m==1) {
			ans=(1.0-p)*1e9;
		}
		else {
			ans=solve(m/2+1,p*p);
			ans-=p*solve((m+1)/2,p*p);
		}

		printf("%.6f %.6f\n",ans,(1e9-ans) );
	}
	return 0;
}
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
#define ii pair<long long int,long long int>

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

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	int t,n;
	inp(t);

	while(t--) {
		inp(n);
		if(n%2==1 || n<4) {
			printf("0\n");
			continue;
		}

		int p=1,q=1;

		int num=n;
		for(int i=2;i*i<=n;i++) {
			if(i*i==n)
				p--;
			if(num%i!=0)
				continue;
			// cout<<"man\n";
			int val=0;
			while(num%i==0) {
				num/=i;
				val++;
			}
			q=q*(val+1);
			if(i==2)
				p=p*(val/2);
			else
				p=p*(val/2 + 1);
			// cout<<i<<" "<<p<<" "<<q<<endl;
		}
		if(num>1)
			q*=2;
		q--;
		int g=gcd(p,q);
		p/=g;
		q/=g;
		if(p==0)
			printf("0\n");
		else
			printf("%d/%d\n", p,q);
	}

	return 0;
}
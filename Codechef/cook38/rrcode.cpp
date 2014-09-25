#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <list>
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

int main() {
	int t,n,k,ans,A[1000];
	string s;

	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		inp(ans);

		for(int i=0;i<n;i++) {
			inp(A[i]);
		}

		cin>>s;

		if(s[0]=='A') {
			if(k) {
				for(int i=0;i<n;i++)
					ans=ans&A[i];
			}
			printf("%d\n",ans);
		}
		else if(s[0]=='O') {
			if(k) {
				for(int i=0;i<n;i++)
					ans=ans|A[i];
			}
			printf("%d\n",ans);
		}

		else {
			if(k&1) {
				for(int i=0;i<n;i++)
					ans=ans^A[i];				
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
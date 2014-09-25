#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
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
	int n,A[100000];

	inp(n);

	for(int i=0;i<n;i++)
		inp(A[i]);

	lli ans=0,num;
	lli val=A[0]%2;

	for(int i=1;i<n;i++) {
		val=(val+A[i])%2;
		if(val)
			ans++;
	}

	num=ans;
	// cout<<num<<endl;
	for(int i=1;i<(n-1);i++) {
		// cout<<i<<" "<<num<<endl;
		if(A[i-1]%2==0) {
			if(A[i]%2==1)
				num--;
			ans+=num;
		}
		else {
			if(A[i]%2==0)
				num--;
			num=n-i-1-num;
			// cout<<i<<" "<<num<<" sai"<<endl;
			ans+=num;
		}

		// cout<<i<<" "<<ans<<endl;
	}

	printf("%lld\n",ans);
	return 0;
}
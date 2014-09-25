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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,m,n,A[1000000],B[1000000],ans;

int main() {
	inp(t);

	while(t--) {
		inp(m);
		inp(n);

		m--;
		n--;
		for(int i=0;i<m;i++)
			inp(A[i]);

		for(int i=0;i<n;i++)
			inp(B[i]);

		sort(A,A+m);
		sort(B,B+n);

		ans=0;
		lli l=1,r=1;

		lli i=m-1,j=n-1;

		// cout<<i<<" "<<j<<endl;
		// printf("mans\n");
		while(i>=0 && j>=0) {
			if(A[i] >= B[j]) {
				// cout<<"man\n";
				// cout<<A[i]<<" "<<l<<endl;
				ans+=(A[i]*l)%mod;
				ans%=mod;
				r++;
				i--;
			}
			else {
				// cout<<B[j]<<" "<<r<<endl;
				ans+=(B[j]*r)%mod;
				ans%=mod;
				l++;
				j--;
			}
			// cout<<i<<" "<<j<<" "<<ans<<endl;
		}

		while(i>=0) {
			ans+=(A[i--]*l)%mod;
			ans%=mod;
		}

		while(j>=0) {
			ans+=(B[j--]*r)%mod;
			ans%=mod;
		}

		printf("%lld\n", ans);
	}

	return 0;
}
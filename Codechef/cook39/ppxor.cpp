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

lli powers[64][2];

lli conv() {
	lli ret=0,num=1;

	for(int i=0;i<64;i++) {
		// cout<<powers[i][1]<<" ";
		ret+=(num)*powers[i][1];
		num<<=1;
	}
	// cout<<"\n"<<ret<<endl;
	return ret;
}

int main() {
	lli t,n,A[100000],ans,num;

	inp(t);


	while(t--) {
		inp(n);
		for(int i=0;i<n;i++)
			inp(A[i]);
		ans=A[n-1];
		num=A[n-1];
		
		for(int i=0;i<64;i++) {
			powers[i][0]=0;
			powers[i][1]=0;
			if(num&1)
				powers[i][1]++;
			else
				powers[i][0]++;
			num>>=1;
			// cout<<powers[i][1]<<" ";
		}

		// cout<<endl<<ans<<endl;
		for(int i=n-2;i>=0;i--) {
			num=A[i];
			// cout<<"man "<<num<<endl;
			for(int j=0;j<64;j++) {
				if(num&1) {
					swap(powers[j][0],powers[j][1]);
					powers[j][1]++;
				}
				else
					powers[j][0]++;
				num>>=1;
			}
			ans+=conv();
			// cout<<ans<<endl;
		}

		printf("%lld\n", ans);
	}

	return 0;
}
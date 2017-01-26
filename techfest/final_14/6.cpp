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

#define mod 1234567891
#define inf 999999999
#define lim 40000000
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int A[lim+1]={0};
int B[lim+1],cnt=0;
int phi[lim+1],dp[lim+1];

int main() {
	for(int i=2;i*i<=lim;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=i;
		}
	}
	cout<<"dude\n";
	phi[1]=1;
	dp[1]=1;

	for(int i=2;i<=lim;i++) {
		// cout<<i<<" "<<A[i]<<endl;
		if(A[i]==0)
			phi[i]=i-1;
		else {
			int n=i;
			cnt=0;
			while(n%A[i]==0) {
				cnt++;
				n/=A[i];
			}
			phi[i]=phi[n]*(A[i]-1);
			for(int j=1;j<cnt;j++)
				phi[i]*=A[i];
		}
		dp[i]=1+dp[phi[i]];
	}

	lli ans=0;
	// for(lli i=1;i<=lim;i++) {
	// 	if(dp[i]==25 && A[i]==0) {
	// 		// cout<<i<<endl;
	// 		ans+=i;
	// 	}
	// }

	// cout<<ans<<endl;

	for(lli i=2;i<=70000;i++) {
		if((i-1)%(i-phi[i])==0 && A[i]>0)
			cout<<i<<" "<<phi[i]<<endl;
	}
	return 0;
}
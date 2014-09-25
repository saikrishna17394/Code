#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 1999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	lli n,k,A[100000],ans=inf,val1,val2,val,num;

	inp(n);
	inp(k);

	for(int i=0;i<n;i++)
		inp(A[i]);

	sort(A,A+n);
	val=0;
	val1=0;
	val2=0;
	for(int i=1;i<k;i++) {
		val+=A[i]-A[0];
	}
	num=val;

	for(int i=1;i<k;i++) {
		num-=(k-i)*(A[i]-A[i-1]);
		val+=num;
	}
	ans=val;

	for(int i=1;i<k;i++)
		val1+=A[i]-A[0];

	for(int i=0;i<(k-1);i++) 
		val2+=A[k-1]-A[i];

	for(int i=1;i+k<=n;i++) {
		// cout<<val1<<" "<<val2<<endl;
		val-=val1;

		val1-=(k-1)*(A[i]-A[i-1]);
		val1+=A[i+k-1]-A[i];


		val2+=k*(A[i+k-1]-A[i+k-2]);
		val2-=(A[i+k-1]-A[i-1]);
		val+=val2;

		// cout<<i<<" "<<val<<" "<<ans<<endl;
		// cout<<val1<<" "<<val2<<endl;
		ans=min(ans,val);
	}

	printf("%lld\n", ans);

	return 0;
}
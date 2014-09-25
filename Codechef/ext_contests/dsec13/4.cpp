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
#define inf 999999999
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
lli n,cnt[50],power[50],t,g,A[50][201][201];

lli ans(lli i,lli j,lli d) {
	// cout<<i<<" "<<j<<" "<<d<<endl;
	if(A[i][j][d]!=-1)
		return A[i][j][d];
	
	lli val=(cnt[i]+j)*power[i],val1=0;
	// cout<<val<<endl;
	if(i==(n-1))
		return val;
	for(int a=0;a<=d && a<=(cnt[i]+j);a++) {
		val1=max(val1,val+ans(i+1,a,d-a));
		val-=power[i];
	}
	A[i][j][d]=val1;
	return val1;
}
int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			inp(cnt[i]);
		for(int i=0;i<n;i++)
			inp(power[i]);

		inp(g);
		memset(A,-1,sizeof A);
		printf("%lld\n", ans(0,0,g));
	}

	return 0;
}
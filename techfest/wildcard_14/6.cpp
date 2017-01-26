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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000004
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli dp[lim];

vvi mul(vvi a,vvi b) {
	vvi ret;
	vector<lli> v(3);
	for(int i=0;i<3;i++)
		ret.push_back(v);

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			ret[i][j]=0;
			for(int k=0;k<3;k++)
				ret[i][j]+=((a[i][k]*b[k][j])%mod);
			ret[i][j]%=mod;
		}
	}

	return ret;
}

vvi pow1(vvi a,lli num) {
	vvi ret;
	vector<lli> v(3);
	for(int i=0;i<3;i++)
		v[i]=0;

	for(int i=0;i<3;i++) {
		ret.push_back(v);
	}
	ret[0][0]=1;
	ret[1][1]=1;
	ret[2][2]=1;

	while(num) {
		if(num&1)
			ret=mul(ret,a);
		a=mul(a,a);
		num/=2;
	}
	return ret;
}
int main() {

	vvi a;
	vector<lli> v(3);
	for(int i=0;i<3;i++)
		v[i]=0;

	for(int i=0;i<3;i++) {
		a.push_back(v);
	}
	a[0][0]=1;
	a[0][1]=1;
	a[0][2]=1;
	a[1][0]=1;
	a[2][1]=1;

	lli val=1;
	for(int i=0;i<15;i++)
		val=val*(lli)10;
	cout<<val<<endl;
	val-=3;
	a=pow1(a,val);


	dp[1]=2;
	dp[2]=3;
	dp[3]=4;

	lli ans=0;
	ans=(a[0][0]*(lli)4)%mod;
	ans+=(a[0][1]*(lli)3)%mod;
	ans+=(a[0][2]*(lli)2)%mod;
	ans%=mod;
	cout<<ans<<endl;


	// for(int i=4;i<lim;i++)
	// 	dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;

	// cout<<dp[6]<<endl;

	return 0;
}
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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,m,ans;

vector<vector<long long int> > A,B;

vvi mul(vvi a,vvi b) {
	vvi ret(m);
	for(int i=0;i<m;i++) {
		ret[i].resize(m);
		for(int j=0;j<m;j++)
			ret[i][j]=0;
	}

	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			for(int k=0;k<m;k++) {
				ret[i][j]+=(a[i][k]*b[k][j])%mod;
				ret[i][j]%=mod;
			}
		}
	}

	return ret;
}

vvi power(vvi a, lli k) {
	vvi ret(m);
	for(int i=0;i<m;i++) {
		ret[i].resize(m);
		for(int j=0;j<m;j++)
			ret[i][j]=0;
		ret[i][i]=1;
	}


	while(k>0) {
		if(k%2==1)
			ret=mul(ret,a);
		a=mul(a,a);
		k/=2;
	}
	return ret;

}
int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		if(m==1) {
			if(n==1)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}

		A.clear();
		B.clear();
		A.resize(m);
		B.resize(m);

		for(int i=0;i<m;i++) {
			B[i].resize(m);
			A[i].resize(m);
			for(int j=0;j<m;j++) {
				if(j==i+1 || j==i-1) {
					B[i][j]=1;
					A[i][j]=1;
				}
				else {
					B[i][j]=0;
					A[i][j]=0;
				}
			}
			A[i][i]=1;
		}

		A=mul(B,A);

		A=power(A,(n-1)/2);

		if(n%2==0) 
			A=mul(A,B);

		ans=0;

		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				ans+=A[i][j];
		ans%=mod;
		printf("%lld\n", ans);

	}

	return 0;
}
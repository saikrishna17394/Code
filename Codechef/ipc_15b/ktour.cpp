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
#define inf 1999999999
#define lim 100010


using namespace std;

typedef vector<vector<int> > vvi;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

vvi mul(vvi a, vvi b) {
	vvi ret;

	for(int i=0;i<a.size();i++) {
		vector<int> v;
		for(int j=0;j<a[i].size();j++) {
			lli val=0;
			for(int k=0;k<b.size();k++) {
				val+=(lli)a[i][k]*(lli)b[k][j];
				val%=mod;
			}
			v.push_back((int)val);
		}
		ret.push_back(v);
	}

	return ret;
}

vvi mat_pow(vvi a,int n) {
	vvi ret;
	for(int i=0;i<a.size();i++) {
		vector<int> v(a.size(),0);
		v[i]=1;
		ret.push_back(v);
	}

	while(n>0) {
		if(n%2==1)
			ret=mul(ret,a);
		a=mul(a,a);
		n/=2;
	}

	return ret;
}

vvi mat_tr(vvi a) {
	vvi ret;

	for(int i=0;i<a.size();i++) {
		vector<int> v;
		for(int j=0;j<a.size();j++)
			v.push_back(a[j][i]);
		ret.push_back(v);
	}

	return ret;
}

int t,m,n,x,y;

int main() {
	inp(t);

	while(t--) {
		inp(m);
		
		inp(x);
		inp(y);

		inp(n);

		vvi a,at;

		vector<int> v1(m,0);
		vvi base(m,v1);
		base[x-1][y-1]=1;

		for(int i=0;i<m;i++) {
			vector<int> v(m,0);
			v[i]=1;
			if(i>0)
				v[i-1]=1;
			if((i+1)<m)
				v[i+1]=1;
			a.push_back(v);
		}
		at=mat_tr(a);

		a=mat_pow(a,n);
		at=mat_pow(at,n);

		a=mul(a,base);
		a=mul(a,at);

		int ans=0;

		for(int i=0;i<m;i++) {
			for(int j=0;j<m;j++)
				ans=(ans+a[i][j])%mod;
		}

		printf("%d\n", ans);

	}
	return 0;
}
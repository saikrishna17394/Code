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
#define lim 10000000

using namespace std;

const double pi = 2 * acos(0.0);

lli pow1(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}


string s,s1;
int n;
string q[100000];

lli A[10],len[10];

int main() {
	cin>>s;

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>q[i];

	for(int i=0;i<10;i++) {
		A[i]=i;
		len[i]=1;
	}

	for(int i=n-1;i>=0;i--) {
		// s1=q[i].substr(3);

		int idx=q[i][0]-'0';

		
		lli val=0,val1=0;

		for(int j=3;j<q[i].size();j++) {
			int d=q[i][j]-'0';
			val=(val*pow1(10,len[d]))%mod;
			val+=A[d];
			val%=mod;
			val1+=len[d];
			val1%=(mod-1);
		}
		A[idx]=val;
		len[idx]=val1;
	}

	lli ans=0;

	for(int i=0;i<s.size();i++) {
		int d=s[i]-'0';
		// cout<<d<<" "<<A[d]<<" "<<len[d]<<endl;
		ans=(ans*pow1(10,len[d])+A[d])%mod;
	}

	printf("%lld\n", ans);
	return 0;
}
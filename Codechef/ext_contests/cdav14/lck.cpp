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

#define mod 1008
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

lli n,A[50],ans;

bool check(lli n) {
	if(n==1)
		return false;
	if(n==2 || n==3)
		return true;
	for(lli k=2;k*k<=n;k++)
		if(n%k==0)
			return false;
	return true;
}

lli sum(lli n) {
	lli ret=0;
	while(n>0) {
		ret+=n%10;
		n/=10;
	}
	return ret;
}

int main() {
	inp(n);

	ans=0;

	for(lli i=0;i<n;i++) {
		inp(A[i]);
		ans*=2;
		if(check(sum(A[i])))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
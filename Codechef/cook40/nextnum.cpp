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
lli fac[19];
int A[10];

lli rank(string s) {

	int len=s.length();

	if(len==1)
		return 1;

	memset(A,0,sizeof A);

	for(int i=0;i<len;i++)
		A[s[i]-'0']++;

	int first=s[0]-'0';
	lli ret=0,val;

	for(int i=0;i<first;i++) {
		if(A[i]) {
			val=fac[len-1];
			A[i]--;
			for(int j=0;j<10;j++) {
				val/=fac[A[j]];
			}
			A[i]++;
			ret+=val;
		}
	}

	return ret+rank(s.substr(1));

}
int main() {
	lli t,n;

	fac[0]=1;
	for(lli i=1;i<19;i++) {
		fac[i]=i*fac[i-1];
		// cout<<i<<" "<<fac[i]<<endl;
	}
	inp(t);

	while(t--) {
		string s;
		cin>>s;
		printf("%lld\n", rank(s));
	}

	return 0;
}
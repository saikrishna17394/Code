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
#define ii pair<long long int,long long int>

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

bool check(lli n) {
	lli k=sqrt(n);
	k=k*k;
	return (k==n);
}
lli t,a,b,A[200],cnt=0;

int main() {
	int ans;

	for(int i=0;i<(1<<20);i++) {
		lli num=0,po=1;
		int mask=i,val;

		for(int j=0;j<10;j++) {
			val=mask&3;
			num*=10;
			if(val==0) {
				;
			}
			else if(val==1) {
				num++;
			}
			else if(val==2) {
				num+=4;
			}
			else {
				num+=9;
			}
			mask>>=2;
		}
		if(num && check(num)) {
			A[cnt++]=num;
		}
	}

	A[cnt++]=(lli)(1e10);
	sort(A,A+cnt);

	inp(t);
	while(t--) {
		inp(a);
		inp(b);

		ans=(int)(lower_bound(A,A+cnt,b)-A);
		if(check(b))
			ans++;
		ans-=(int)(lower_bound(A,A+cnt,a)-A);

		printf("%d\n", ans);
	}

	return 0;
}
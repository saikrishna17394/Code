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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
string a,b;

lli po2[520000],ans;


int main() {
	cin>>a;
	cin>>b;

	po2[0]=1;

	for(int i=1;i<520000;i++)
		po2[i]=(po2[i-1]*2)%mod;

	ans=0;

	int nb=b.length(),na=a.length();

	// cout<<na<<" "<<nb<<endl;

	if(nb>=na) {
		for(int i=0;i<(nb-na);i++) {
			if(b[i]=='1') {
				// cout<<i<<endl;
				ans+=po2[nb-i+314159];
				ans-=po2[nb-i-1];
				ans%=mod;
				if(ans<0)
					ans+=mod;
				// cout<<ans<<endl;
			}
			// cout<<"y "<<i<<endl;
		}

		// cout<<ans<<endl;
		lli help=1;

		lli val=0,val1=0;
		for(int i=nb-na;i<nb;i++) {

			val=val*2;
			val1=val1*2;
			if(a[i-nb+na]=='1')
				val++;
			else
				val1++;
			val%=mod;
			val1%=mod;

			// cout<<"y "<<i<<" "<<b[i]<<" "<<val<<" "<<val1<<endl;
			if(b[i]=='0') {
				ans+=val;
			}
			else {
				ans+=val1;
				ans+=po2[nb-i+314159];
				ans-=po2[nb-i-1+help];
			}
			ans%=mod;
			if(ans<0)
				ans+=mod;
			help++;
		}

	}
	else {
		lli val=0,val1=0;

		lli kri=na-nb;
		for(int i=0;i<(na-nb);i++) {
			val=val*2;
			val1=val1*2;
			if(a[i]=='1') {
				val++;
				ans+=(po2[na-i-1]*kri)%mod;
				ans%=mod;
			}
			else {
				val1++;
			}
			val%=mod;
			val1%=mod;
			kri--;
		}

		// lli help=;

		for(int i=na-nb;i<na;i++) {
			val=val*2;
			val1=val1*2;

			if(a[i]=='1')
				val++;
			else
				val1++;
			val%=mod;
			val1%=mod;

			if(b[i-na+nb]=='0') {
				ans+=val;
			}
			else {
				ans+=val1;
				ans+=po2[na-i+314159];
				ans-=po2[na];				
			}
			ans%=mod;
			if(ans<0)
				ans+=mod;
			// help++;
		}

		// printf("what\n");
	}

	lli num=314159;
	for(int i=na-1;i>=0;i--) {
		if(a[i]=='1')
			ans+=(po2[na-i-1]*num)%mod;
		ans%=mod;
		num--;
	}
	if(ans<0)
		ans+=mod;
	printf("%lld\n", ans);

	return 0;
}
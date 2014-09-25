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

#define mod 1000000003
#define inf 999999999
#define lim 100010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int te,n,d,a,t[10000],v[10000];
double ans,val,num;
int main() {
	inp(te);

	while(te--) {
		inp(n);
		inp(a);
		inp(d);

		for(int i=0;i<n;i++) {
			inp(t[i]);
			inp(v[i]);
		}
		ans=t[0];
		// cout<<"dud "<<ans<<endl;
		val=(double)v[0];
		val*=val;
		val/=2.0;
		val/=(double)a;

		if(val>=(double)d) {
			val=d;
			val*=2.0;
			val/=(double)a;
			val=sqrt(val);
			ans+=val;
		}
		else {
			double val1=v[0];
			val1/=(double)a;
			ans+=val1;
			ans+=(double)(d-(double)val)/(double)v[0];
		}
		printf("%.7f\n",ans );
		for(int i=1;i<n;i++) {
			num=t[i];
			val=(double)v[i];
			val*=val;
			val/=2.0;
			val/=(double)a;

			if(val>=(double)d) {
				val=d;
				val*=2.0;
				val/=(double)a;
				val=sqrt(val);
				num+=val;
			}
			else {
				double val1=v[i];
				val1/=(double)a;
				num+=val1;
				num+=(double)(d-(double)val)/(double)v[i];
			}
			ans=max(ans,num);
			printf("%.7f\n", ans);
		}
	}

	return 0;
}
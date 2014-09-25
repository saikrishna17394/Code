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

lli t,m,h,n,D[1000000],a,b,ind,ans;

lli cum[1000];

int A[1000000];

int main() {

	inp(t);

	while(t--) {
		inp(h);

		inp(n);
		inp(m);

		inp(a);
		inp(b);
		inp(ind);

		for(lli i=0;i<m;i++)
			inp(D[i]);

		memset(A,-1,sizeof A);

		lli cur=ind;
		lli ans=0;

		for(int i=1;i<=(m+1);i++) {
			// cout<<i<<" "<<cur<<" "<<A[cur]<<endl;
			if(A[cur]!=-1) {
				lli num=ind;
				for(int j=1;j<A[cur] && j<n;j++) {
					ans+=D[num];
					// cout<<"man "<<j<<" "<<num<<" "<<D[num]<<" "<<ans<<endl;
					num=(a*num+b)%m;
				}

				lli len=i-A[cur];

				for(int j=A[cur];j<i && j<n;j++) {
					lli q=(n-j-1)/len;
					// if((n-j)%len==0)
					// 	q--;
					// lli val;
					// val=(n-j)*(q+1);
					// val-=(len*q*(q+1))/2;					
					ans+=(q+1)*D[num];
					// cout<<"wat "<<j<<" "<<num<<" "<<D[num]<<" "<<ans<<endl;
					num=(a*num+b)%m;
				}

				break;
			}
			A[cur]=i;
			cur=(a*cur+b)%m;
		}
		
		// lli cur=ind;
		// for(int i=0;i<n;i++) {
		// 	cum
		// }
		ans*=h;

		if(ans%2==0)
			printf("%lld.0\n", ans/2);
		else
			printf("%lld.5\n", ans/2);
	}

	return 0;
}
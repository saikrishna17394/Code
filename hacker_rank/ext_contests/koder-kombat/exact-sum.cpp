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
#define ii pair<long long int,int>


using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,B[100],b;

int vis[100010]={0};
lli dp[100010];

int main() {
	inp(t);

	while(t--) {
		// printf("whazza\n");
		inp(n);
		inp(b);
		set<lli> s1;
		for(lli i=0;i<b;i++) {
			inp(B[i]);
			s1.insert(B[i]);
		}
		vector<lli> v(s1.begin(),s1.end());
		
		b=v.size();
		for(lli i=0;i<b;i++) {
			B[i]=v[i];
			if(B[i]>n) {
				b=i;
				break;
			}
		}
		if(b==0) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		lli mod=B[b-1];
		if(b==1) {
			if(n%mod!=0)
				printf("IMPOSSIBLE\n");
			else
				printf("%lld\n", n/mod);
		}

		for(lli i=0;i<mod;i++) 
			dp[i]=n+1;

		lli inf=n+1;

		set<ii> s;

		for(lli i=0;i<(b-1);i++) {
			cout<<i<<" "<<B[i]<<endl;
			s.insert(ii(B[i],B[i]));
			dp[B[i]]=B[i];
		}

		bool ok=false;

		while(!s.empty()) {
			ii p=*s.begin();
			cout<<p.first<<" "<<p.second<<" "<<mod<<endl;
			s.erase(p);

			if(p.second%mod==n%mod){
				ok=true;
				break;
			}

			for(lli i=0;i<(b-1);i++) {
				lli next=(p.second+B[i])%mod;
				if((p.first+B[i])<dp[next]) {
					if(dp[next]<inf) {
						s.erase(ii(dp[next],next));
					}
					dp[next]=p.first+B[i];
					s.insert(ii(p.first+B[i],next));
				}
			}
		}

		if(!ok || dp[n%mod]>n) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		lli ans=(n-dp[n%mod])/mod;
		
	}

	return 0;
}
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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int m,a,ind;
	int cost[15],area[15],discounts[15][15];
	double ans,dp[1<<15],disc;
	int areas[1<<15];


	inp(m);

	while(m) {
		for(int i=0;i<m;i++) {
			inp(cost[i]);
			inp(area[i]);
			inp(a);

			for(int j=0;j<m;j++) {
				discounts[i][j]=100;
			}

			while(a--) {
				inp(ind);
				ind--;
				inp(discounts[i][ind]);
				discounts[i][ind]=100-discounts[i][ind];
				// cout<<i<<" "<<ind<<" "<<discounts[i][ind]<<endl;
			}

		}

		int lim=1<<m,mask,mask1;
		dp[0]=0;
		areas[0]=0;
		ans=inf;

		double val;

		for(int i=1;i<lim;i++) {
			// cout<<ans<<endl;
			mask=i;
			dp[i]=inf;
			areas[i]=0;

			for(int j=0;j<m;j++) {
				if(mask&1) {
					mask1=i^(1<<j);
					disc=1;
					for(int k=0;k<m;k++) {
						if(mask1&1) {
							// cout<<k<<" dudeee "<<j<<endl;
							// cout<<j<<" "<<k<<" "<<discounts[j][k]<<endl;
							disc*=((double)discounts[k][j]/100.0);
						}
						mask1>>=1;
					}

					val=(double)cost[j];
					val*=disc;

					dp[i]=min(dp[i],val+dp[i^(1<<j)]);
					areas[i]+=area[j];
					// cout<<val<<" "<<dp[i]<< "  \\ ";
				}

				mask>>=1;
				// cout<<ans<<endl;
			}

			ans=min(ans,dp[i]/(double)(areas[i]));		
		}

		printf("%.4f\n", ans);

		inp(m);	
	}
	return 0;
}
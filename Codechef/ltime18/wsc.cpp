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

int dp[1<<10][2],t,n,m;
vector<int> g[10];
int pos[1<<10];


void dfs(int mask,int idx) {
	// cout<<"-> ("<<mask<<","<<idx<<")\n";
	dp[mask][idx]=1;

	int num=mask;

	int msk=((1<<n)-1)^mask;
	for(int i=0;i<n;i++) {
		if(num%2==1) {
			if(pos[mask^(1<<i)]==1 && dp[msk^(1<<i)][idx^1]==0)
				dfs(msk^(1<<i),idx^1);
		}
		num/=2;
	}

	// cout<<mask<<" "<<pos[mask]<<" "<<msk<<endl;
	if(pos[mask]==1 && dp[msk][idx^1]==0)
		dfs(msk,idx^1);

}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		int a,b;
		for(int i=0;i<n;i++)
			g[i].clear();
		
		for(int i=0;i<m;i++) {
			inp(a);
			inp(b);
			a--;
			b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}



		for(int i=0;i<(1<<n);i++) {
			dp[i][0]=0;
			dp[i][1]=0;
		}

		pos[0]=1;
	
		for(int i=1;i<(1<<n);i++) {
			int x=i-(i&-i);
			int val=i&-i;
			if(val==i) {
				pos[i]=1;
				// cout<<i<<" w: "<<pos[i]<<endl;
				continue;
			}

			int num=0;
			while(val>1) {
				num++;
				val/=2;
			}
			pos[i]=0;
			if(pos[x]==1) {
				pos[i]=1;
				for(int j=0;j<g[num].size();j++) {
					if( ((1<<g[num][j])&i)!=0) {
						pos[i]=0;
						// cout<<i<<" : "<<pos[i]<<endl;
						break;
					}
				}
			}
			// cout<<i<<" : "<<pos[i]<<endl;
		}		

		dfs((1<<n)-1,0);

		if(dp[(1<<n)-1][1]==1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
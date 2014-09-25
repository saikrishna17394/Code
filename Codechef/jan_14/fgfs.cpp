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

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,cnt,n,k,num,ans,len;
vector<ii> A[100000];
int dp[100001];
ii p;
map<int,int> m;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		cnt=0;
		m.clear();

		for(int i=0;i<n;i++) {
			inp(p.first);
			inp(p.second);
			inp(num);
			if(m.find(num)==m.end()) {
				A[cnt].clear();
				m[num]=cnt++;
			}
			A[m[num]].push_back(p);
		}
		ans=0;

		for(int i=0;i<cnt;i++) {
			sort(A[i].begin(),A[i].end());
			len=A[i].size();
			dp[len]=0;

			for(int j=len-1;j>=0;j--) {
				int l=j+1,r=len,mid;

				while(l<r) {
					mid=(l+r)/2;
					if(A[i][j].second<=A[i][mid].first)
						r=mid;
					else
						l=mid+1;
				}

				dp[j]=max(dp[j+1],1+dp[l]);
			}
			ans+=dp[0];
		}
		printf("%d\n", ans);
	}

	return 0;
}
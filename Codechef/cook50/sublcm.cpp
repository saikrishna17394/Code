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
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int t,n,A[100000],dp[100000];
vector<int> v[100000];

int vis[1000001];

int B[1000001]={0};

int main() {
	for(int i=2;i*i<=lim;i++) {
		if(B[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				B[j]=i;
		}
	}
	


	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i]);
			v[i].clear();
			int num=A[i];
			while(num>1) {
				if(B[num]==0) {
					v[i].push_back(num);
					num=1;
					continue;
				}

				int x=B[num];
				while(num%x==0)
					num/=x;
				v[i].push_back(x);
			}

		}

		memset(vis,-1,sizeof vis);

		for(int j=0;j<v[0].size();j++)
			vis[v[0][j]]=0;
		dp[0]=1;

		for(int i=1;i<n;i++) {
			set<int> s;

			int idx=i-dp[i-1];

			int l=idx;

			for(int j=0;j<v[i].size();j++) {
				// cout<<i<<" "<<j<<" "<<v[i][j]<<endl;
				if(vis[v[i][j]]>=idx)
					l=max(l,vis[v[i][j]]+1);
			}
			
			dp[i]=i-l+1;
			
			for(int j=0;j<v[i].size();j++) {
				vis[v[i][j]]=i;
			}

		}

		int ans=0;

		for(int i=0;i<n;i++)
			ans=max(ans,dp[i]);

		if(ans==1)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
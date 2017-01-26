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

int t,n,A[100000];
lli ans;

ii B[100000],C[100000];
int cnt1=0,cnt2=0;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		cnt1=0;
		cnt2=0;
		for(int i=0;i<n;i++) {
			inp(A[i]);
			if(A[i]>=0)
				B[cnt1++]=ii(i,A[i]);
			else {
				// cout<<A[i]<<" fuck man\n";
				C[cnt2++]=ii(i,-A[i]);
				// cout<<C[cnt2-1].first<<" "<<C[cnt2-1].second<<endl;
			}
		}
		ans=0;

		int idx1=0,idx2=0;
		while(idx1<cnt1) {
			// cout<<idx1<<" "<<B[idx1].second<<endl;
			// cout<<idx2	<<" "<<C[idx2].second<<endl;
			if(B[idx1].second==0) {
				idx1++;
				continue;
			}
			int val=min(B[idx1].second,C[idx2].second);
			B[idx1].second-=val;
			C[idx2].second-=val;
			ans+=(lli)val*(lli)abs(B[idx1].first-C[idx2].first);
			if(C[idx2].second==0)
				idx2++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
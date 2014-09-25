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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

bool cmp(ii a,ii b) {
	if(a.first!=b.first)
		return a.first<b.first;
	return a.second>b.second;
}

int main() {
	int n,ans,t;
	ii A[20000];

	int B[20000];
	// using this as a set
	// could have used as the lower bound function
	// but need the longest non decreasing fucntion
	// multiset aa sodi endukani maname neat implement cheskunam

	inp(t);

	while(t--) {

		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}

		sort(A,A+n,cmp);

		int cnt=0,l,r,mid;

		for(int i=0;i<n;i++) {
			l=0;
			r=cnt-1;

			// cout<<i<<endl;
			while(l<=r) {

				if(l==r) {
					if(A[i].second<=B[l])
						l++;
					break;
				}
				// cout<<l<<" "<<r<<endl;
				mid=(l+r)/2;

				if(A[i].second<=B[mid]) {
					l=mid+1;
				}
				else {
					r=mid;
				}
			}

			B[l]=A[i].second;

			if(l==cnt)
				cnt++;

		}

		ans=cnt;

		printf("%d\n",ans );
	}

	return 0;
}
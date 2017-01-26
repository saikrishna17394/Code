#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<long long int,long long int>
#define mp make_pair
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

lli t,n,ans;
lli P[100],A[100];

int main() {
	// freopen("inp","r",stdin);
	// freopen("B-small-attempt1.in", "r", stdin);	
	freopen("B-large.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	for(lli a=1;a<=t;a++) {
		inp(n);

		ii p;
		p.first=0;
		p.second=1e15;
		for(lli i=0;i<n;i++) {
			inp(P[i]);
			inp(A[i]);
			if(P[i]==100) {
				ii p1;
				p1.first=A[i];
				p1.second=A[i];
				p.first=max(p.first,p1.first);
				p.second=min(p.second,p1.second);
				continue;
			}
			A[i]*=100;

			ii p1;
			lli l=1,r=1e15;

			while(l<r) {
				lli m=(l+r)/2;

				lli val=m*P[i]+(m-1);
				if(val>=A[i]) {
					r=m;
				}
				else {
					l=m+1;
				}
			}

			p1.first=l;

			l=1;
			r=1e15;

			while(l<r) {
				lli m=(l+r)/2;
				m++;

				lli val=m*P[i];
				if(A[i]>=val) {
					l=m;
				}
				else {
					r=m-1;
				}
			}
			p1.second=l;

			// cout<<p1.first<<" "<<p1.second<<endl;
			p.first=max(p.first,p1.first);
			p.second=min(p.second,p1.second);
		}


		if(p.first!=p.second)
			ans=-1;
		else
			ans=p.first;
		printf("Case #%lld: %lld\n",a,ans );
	}


	return 0;
}
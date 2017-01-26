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
#define ii pair<long long int,long long int>

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

int t,n,m,mice[1<<18],hole[1<<18];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		for(int i=0;i<n;i++)
			inp(mice[i]);
		sort(mice,mice+n);

		for(int i=0;i<m;i++)
			inp(hole[i]);
		sort(hole,hole+m);

		int l=0,r=1<<30;
		while(l<r) {
			int mid=(l+r)/2;
			int i=0,j=0;

			bool ok=false;
			while(1) {
				if(i==n) {
					ok=true;
					break;
				}
				if(j==m)
					break;
				if(abs(mice[i]-hole[j])<=mid) {
					i++;
					j++;
				}
				else {
					j++;
				}
			}

			if(ok)
				r=mid;
			else
				l=mid+1;
		}
		printf("%d\n", l);
	}	

	return 0;
}
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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,k,n;
lli A[100000];
ii B[100000];

lli fun(lli i,lli j) {
	lli ret=1;

	for(lli a=i;a<=j;a++) {
		ret*=B[a].first;
		ret*=B[a].second;
		ret%=mod;
	}
	if(ret<0)
		ret+=mod;
	return ret;
}

int main() {

	inp(t);

	while(t--) {
		inp(n);
		inp(k);

		lli cnt=0;
		for(lli i = 0;i<n;i++) {
			inp(A[i]);
			if(A[i]<0)
				B[i]=ii(-A[i],-1);
			else
				B[i]=ii(A[i],1);

			if(A[i]==0)
				cnt++;
		}

		if(cnt>(n-k)) {
			printf("0\n");
			continue;
		}
		sort(B,B+n);

		lli val=1;

		for(lli i=0;i<k;i++) {
			val*=B[n-i-1].second;
		}

		lli ans;

		if(val < 0) {
			vector<ii> v;
			for(lli i=n-k;i<n;i++) {
				if(B[i].second>0) {
					for(lli j=n-k-1;j>=0;j--) {
						if(B[j].second<0) {
							v.push_back(ii(i,j));
							break;
						}
					}
					break;
				}
			}

			for(lli i=n-k;i<n;i++) {
				if(B[i].second<0) {
					for(lli j=n-k-1;j>=0;j--) {
						if(B[j].second>0 && B[j].first>0) {
							v.push_back(ii(i,j));
							break;
						}
					}
					break;
				}
			}

			if(v.size()==0) {
				if(cnt>0)
					ans=0;
				else
					ans=fun(0,k-1);
			}
			else if(v.size()==1) {
				swap(B[v[0].first],B[v[0].second]);
				ans=fun(n-k,n-1);
			}
			else {
				ii p1=v[0],p2=v[1];

				if((p1.second*p2.first)>=(p2.second*p1.first))
					swap(B[v[0].first],B[v[0].second]);
				else
					swap(B[v[1].first],B[v[1].second]);
				ans=fun(n-k,n-1);
			}
		}
		else
			ans = fun(n-k,n-1);

		cout<<ans<<endl;
	}

	return 0;
}
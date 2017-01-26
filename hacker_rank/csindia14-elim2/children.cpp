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

lli ans,n,A[300000],val;
vector<ii> v,v1;

int main() {
	inp(n);
	val=0;
	for(int i=0;i<n;i++) {
		inp(A[i]);
		val+=A[i];
	}
	val/=n;
	ans=0;

	for(int i=0;i<n;i++) {
		if(A[i]>val)
			v.push_back(ii(A[i]-val,i));
		else if(A[i]<val)
			v1.push_back(ii(val-A[i],i));
	}
	
	int idx=0;
	for(int i=0;i<v.size();i++) {
		lli rem=v[i].first;
		while(rem>0) {
			val=min(rem,v1[idx].first);
			ans+=val*(lli)(abs(v[i].second-v1[idx].second));
			rem-=val;
			v1[idx].first-=val;
			if(v1[idx].first==0)
				idx++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
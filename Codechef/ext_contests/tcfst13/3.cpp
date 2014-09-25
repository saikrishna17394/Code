#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#define lli long long int
#define ii pair<int,int>

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

int main() {
	lli n,A[100000],num,prev,ans;
	map<lli,int> m,m1;
	inp(n);


	for(int i=0;i<n;i++) {
		inp(num);
		if(m.find(num)!=m.end())
			m[num]++;
		else
			m[num]=1;
	}

	for(map<lli,int>::iterator it=m.begin();it!=m.end();it++) {
		if(it->second>1) {
			m[it->first+1]+=(it->second)/2;
			m[it->first]=(it->second)%2;
		}
	}

	map<lli,int>::reverse_iterator it=m.rbegin();
	ans=it->first;
	// cout<<ans<<endl;
	ans++;

	for(map<lli,int>::iterator it=m.begin();it!=m.end();it++) {
		// cout<<it->first<<" "<<it->second<<endl;
		if(it->second>0)
			ans--;
	}
	printf("%lld\n", ans);
	return 0;
}
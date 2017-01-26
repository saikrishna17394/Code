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
#define vvi vector<vector<long long int> >

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

int t,n,ans,len;
string s;

vector<int> v;

int main() {
	inp(t);

	while(t--) {
		cin>>s;

		len=s.length();
		ans=0;
		v.clear();

		for(int i=0;i<len;i++) {
			ans+=min(s[i]-'A','Z'-s[i]+1);
			if(s[i]!='A' && i>0) {
				v.push_back(i);
			}
		}

		// cout<<ans<<" sadf"<<endl;
		if(v.size()==0) {
			printf("%d\n", ans);
			continue;
		}

		n=v.size();

		int val=min(v[n-1],len-v[0]);

		for(int i=0;i<n;i++) {
			if(i<(n-1))
				val=min(val,2*v[i]+len-v[i+1]);
			if(i>0)
				val=min(val,v[i-1]+2*(len-v[i]));
		}

		printf("%d\n", ans+val);
	}

	return 0;
}
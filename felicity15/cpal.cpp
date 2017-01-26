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
#define inf (lli)1e16

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int dp[86400];

bool check(int h,int m,int s) {
	string s1="";

	s1+=h/10+'0';
	s1+=h%10+'0';

	s1+=m/10+'0';
	s1+=m%10+'0';

	s1+=s/10+'0';
	s1+=s%10+'0';

	// cout<<h<<" "<<m<<" "<<s<<" "<<s1<<endl;
	if(s1[0]==s1[5] && s1[1]==s1[4] && s1[2]==s1[3])
		return true;
	return false;
}

int main() {
	
	dp[0]=0;

	for(int i=0;i<86400;i++) {
		int tim=i;
		int sec=tim%60;

		tim/=60;

		int min=tim%60;

		int hr=tim/60;

		if(i>0)
			dp[i]=dp[i-1];

		if(check(hr,min,sec))
			dp[i]++;
	}

	int q;

	inp(q);

	while(q--) {
		int h,m,s;
		inp(h);
		inp(m);
		inp(s);

		int ans=dp[h*3600+m*60+s];

		// cout<<h<<" "<<m<<" "<<s<<" "<<ans<<endl;

		if(check(h,m,s))
			ans--;

		inp(h);
		inp(m);
		inp(s);
		// cout<<h<<" "<<m<<" "<<s<<" "<<dp[h*3600+m*60+s]<<endl;
		ans=dp[h*3600+m*60+s]-ans;

		printf("%d\n", ans);
	}
	return 0;
}
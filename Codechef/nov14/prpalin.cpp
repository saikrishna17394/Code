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

int main() {
	cin.sync_with_stdio(false);

	int t,n;
	string s;
	cin>>t;

	while(t--) {
		cin>>s;
		n=s.length();

		int idx=-1;
		for(int i=0;i<n;i++) {
			int r=n-i-1;
			if(i>=r)
				break;
			if(s[i]!=s[r]) {
				idx=i;
				break;
			}
		}

		if(idx==-1) {
			printf("YES\n");
			continue;
		}

		bool ok=true;

		int r=n-1;
		for(int i=0;i<r;i++,r--) {
			// cout<<i<<" "<<r<<" "<<idx<<endl;
			if(i==idx) {
				r++;
				continue;
			}
			if(s[i]!=s[r]) {
				ok=false;
				break;
			}
		}

		if(ok) {
			printf("YES\n");
			continue;
		}

		ok=true;
		r=n-1;
		for(int i=0;i<r;i++,r--) {
			// cout<<i<<" "<<r<<" "<<idx<<endl;
			// printf("broooooo\n");
			if(r==(n-idx-1)) {
				i--;
				continue;
			}
			if(s[i]!=s[r]) {
				ok=false;
				break;
			}
		}

		if(ok) {
			printf("YES\n");
			continue;
		}
		printf("NO\n");

	}

	return 0;
}
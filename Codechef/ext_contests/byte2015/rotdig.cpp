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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[9],t,n;
string s;

int main() {
	inp(t);	
	while(t--) {
		cin>>s;
		n=s.length();

		int ans=-1;

		set<int> s1;
		int idx=-1;

		bool ok=false;

		for(int i=0;i<s.length();i++) {
			if(s[i]=='0') {
				idx=i;
				break;
			}
			int val=0;
			for(int j=0;j<n;j++) {
				val*=10;
				val+=s[(i+j)%n]-'0';
			}

			ans=max(ans,val);

			if(i==(n-1)) {
				ok=true;
				break;
			}
		}

		if(ok) {
			printf("%d\n", ans);
			continue;
		}

		ans=-1;

		for(int i=1;i<n;i++) {

			int val=0;
			for(int j=0;j<n;j++) {
				int idx1=(i+j)%n;
				if(idx1<=i && s[idx1]=='0') {
					continue;
				}
				val*=10;
				val+=s[(i+j)%n]-'0';
			}

			ans=max(ans,val);
		}

		for(int i=n-1;i>0;i--) {
			int val=0;
			for(int j=0;j<n;j++) {
				int idx1=(i+j)%n;
				if(idx1>=i && s[idx1]=='0') {
					continue;
				}
				val*=10;
				val+=s[(i+j)%n]-'0';
			}

			ans=max(ans,val);			
		}

		printf("%d\n", ans);
	}
	return 0;
}
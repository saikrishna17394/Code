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


int t;
string s;

int main() {
	inp(t);

	while(t--) {
		cin>>s;
		map<char,int> m;

		int ans=0;

		for(int i=0;i<s.length();i++) {
			int val=1;
			m.clear();
			m[s[i]]=1;
			for(int j=i+1;j<s.length();j++) {
				if(m.find(s[j])==m.end()) {
					m[s[j]]=1;
					val++;
				}
				else
					break;
			}
			ans=max(ans,val);
		}
		cout<<ans<<endl;
	}	

	return 0;
}
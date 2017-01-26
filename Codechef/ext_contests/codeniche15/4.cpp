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

		set<string> m;

		for(int i=0;i<s.length();i++) {
			string s1="";
			s1+=s[i];
			m.insert(s1);
			for(int j=i-1;j>=0;j--) {
				s1=s[j]+s1;
				m.insert(s1);
			}
		}
		cout<<m.size()<<endl;
	}

	return 0;
}
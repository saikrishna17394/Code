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

int main() {
	int t;
	string s;
	inp(t);

	while(t--) {
		getline(cin,s);

		string s1="";
		for(int i=0;i<s.length();i++) {
			if(s[i]>='a' && s[i]<='z')
				s1+=s[i];
			else if(s[i]>='A' && s[i]<='Z')
				s1+=s[i];
			else if(s[i]>='0' && s[i]<='9')
				s1+=s[i];
		}

		bool ok=true;
		int n=s1.length();

		for(int i=0;i<n;i++) {
			if(s1[i]!=s1[n-i-1]) {
				ok=false;
				break;
			}
		}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
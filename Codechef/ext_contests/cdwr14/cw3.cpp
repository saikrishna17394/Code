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

string s;
int main() {

	while(cin>>s) {
		int level=0,len=s.length(),idx=0;

		while(s[idx]=='#') {
			level++;
			idx++;
		}
		// cout<<s<<endl;
		if(s[idx+1]=='/')
			continue;

		if(s[len-1]=='>') {
			if(s[len-2]=='/')
				len--;

			cout<<s.substr(idx+1,len-idx-2)<<" "<<level<<" 0"<<endl;
			continue;
		}

		cout<<s.substr(idx+1,len-idx-1)<<" "<<level<<" ";
		int attr=0;

		while(cin>>s) {
			attr++;
			len=s.length();
			if(s[len-1]=='>')
				break;
		}
		cout<<attr<<endl;
	}
	return 0;
}
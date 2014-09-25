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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
set<string> s;
string s1,s2,s3;

string add(string a,string b) {
	string ret;
	int carry=0,val;

	for(int i=0;i<a.length();i++) {
		val=a[i]-'0';
		val+=b[i]-'0'+carry;
		ret+=val%10+'0';
		carry=val/10;
	}
	for(int i=a.length();i<b.length();i++) {
		val=b[i]-'0'+carry;
		carry=val/10;
		ret+=val%10+'0';
	}
	if(carry)
		ret+='1';
	return ret;
}

string rev(string a) {
	string ret;

	for(int i=a.length()-1;i>=0;i--)
		ret+=a[i];
	return ret;
}
int main() {
	s.insert("0");
	s.insert("1");

	s1="0";
	s2="1";
	while(1) {
		s3=add(s1,s2);
		if(s3.length()>1000)
			break;
		s.insert(s3);
		// cout<<rev(s3)<<endl;
		s1=s2;
		s2=s3;
	}

	int t;
	inp(t);

	while(t--) {
		cin>>s1;
		if(s.find(rev(s1))!=s.end())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
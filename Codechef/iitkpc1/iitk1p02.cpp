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

string s;
int A[26]={0};

int main() {
	cin>>s;

	int val=0;
	val++;
	A[s[0]-'a']=1;

	for(int i=1;i<s.length();i++) {
		if(s[i]==s[i-1]) {
			val++;
			A[s[i]-'a']=max(A[s[i]-'a'],val);
		}
		else {
			val=1;
			A[s[i]-'a']=max(A[s[i]-'a'],val);	
		}
	}

	char x='a';
	val=A[0];
	// cout<<val<<endl;
	for(int i=1;i<26;i++) {
		if(A[i]>val) {
			val=A[i];
			x=i+'a';
		}
	}

	cout<<x<<endl;
	printf("%d\n", val);

	return 0;
}
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

string A[10002];

string add(string& s1,string& s2) {
	string ret="";

	int carry=0;

	for(int i=0;i<s2.size();i++) {
		int inc=s2[i]-'0'+s1[i]-'0'+carry;
		ret+='0'+inc%10;
		carry=inc/10;
	}

	for(int i=s2.size();i<s1.size();i++) {
		int inc=s1[i]-'0'+carry;
		ret+='0'+inc%10;
		carry=inc/10;
	}

	if(carry)
		ret+='0'+carry;

	return ret;
}

int main() {
	A[0]="0";
	A[1]="1";

	for(int i=2;i<10002;i++) {
		A[i]=add(A[i-1],A[i-2]);
		// if(i<10)
		// 	cout<<A[i]<<endl;
	}

	int n;

	while(scanf("%d",&n)!=EOF) {
		string s=add(A[n+1],A[n-1]);
		for(int i=s.size()-1;i>=0;i--)
			printf("%c",s[i] );
		printf("\n");
	}

	return 0;
}
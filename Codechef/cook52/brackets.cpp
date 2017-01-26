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

string s;
int n,ans=0,t;

int main() {
	cin>>t;

	while(t--) {
		cin>>s;
		n=s.length();

		ans=0;
		int val=0;
		for(int i=0;i<n;i++) {
			if(s[i]=='(')
				val++;
			else
				val--;
			ans=max(ans,val);
		}

		for(int i=0;i<ans;i++)
			printf("(");
		for(int i=0;i<ans;i++)
			printf(")");
		printf("\n");

	}

	return 0;
}
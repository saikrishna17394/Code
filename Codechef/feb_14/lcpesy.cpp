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

string s1,s2;
int A[256],B[256];
int main() {
	int t;
	inp(t);

	while(t--) {
		cin>>s1;
		cin>>s2;
		memset(A,0,sizeof A);
		for(int i=0;i<s1.length();i++)
			A[s1[i]]++;
		memset(B,0,sizeof B);
		for(int i=0;i<s2.length();i++)
			B[s2[i]]++;

		int ans=0;
		for(int i=0;i<256;i++) {
			ans+=min(A[i],B[i]);
		}
		printf("%d\n", ans);
	}


	return 0;
}
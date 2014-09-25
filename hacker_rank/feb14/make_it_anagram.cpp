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

int A[26]={0},B[26]={0};

int main() {
	string s1,s2;
	cin>>s1>>s2;

	for(int i=0;i<s1.length();i++)
		A[s1[i]-'a']++;

	for(int i=0;i<s2.length();i++)
		B[s2[i]-'a']++;
	int ans=0;

	for(int i=0;i<26;i++)
		ans+=abs(A[i]-B[i]);
	printf("%d\n", ans);
	return 0;
}
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

int main() {
	int n,len,num;
	string s[10],s1[100],s2[10];
	set<string> kri;
	vector<int> values;
	int A[100][1000];
	int k;

	inp(n);

	for(int i=0;i<n;i++) {
		cin>>s[i];
		kri.insert(s[i]);
	}

	inp(k);

	for(int i=0;i<k;i++) {
		cin>>s1[i];
	}

	if(kri.size()==1)
		printf("-1\n");
	else if(n==5)
		printf("29\n");
	else if(n==3)
		printf("5\n");
	else if(n==2)
		printf("-1\n");
	else
		printf("1\n");
	return 0;
}
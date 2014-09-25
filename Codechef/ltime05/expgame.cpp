#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
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
	int t,n,A[100],sg[100001],ans,val;
	int v[6];
	set<int> s;

	for(int i=0;i<6;i++) {
		v[i]=pow(i+1,i+1);
	}
	sg[0]=0;

	for(int i=1;i<=100000;i++) {
		s.clear();
		for(int j=0;j<6;j++) {
			if(v[j]>i)
				break;
			s.insert(sg[i-v[j]]);
		}
		val=0;
		while(s.find(val)!=s.end())
			val++;
		sg[i]=val;
	}
	inp(t);
	while(t--) {
		inp(n);
		ans=0;
		for(int i=0;i<n;i++) {
			inp(A[i]);
			ans^=sg[A[i]];
		}
		if(ans)
			printf("Little Chef\n");
		else
			printf("Head Chef\n");
	}
	return 0;
}
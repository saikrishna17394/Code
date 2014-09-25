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

int A[500001],n;
set<int> s;

int main() {
	A[0]=0;
	s.insert(0);

	for(int i=1;i<500001;i++) {
		if(A[i-1]>=i && s.find(A[i-1]-i)==s.end()) {
			A[i]=A[i-1]-i;
		}
		else {
			A[i]=A[i-1]+i;
		}
		s.insert(A[i]);
	}

	while(1) {
		inp(n);
		if(n==-1)
			break;
		printf("%d\n", A[n]);
	} 

	return 0;
}
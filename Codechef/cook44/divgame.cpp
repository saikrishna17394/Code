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
int A[100000001],t,n;

int solve(int i) {
	if(A[i]!=-1)
		return A[i];

	if(A[i-1]==0) {
		A[i]=1;
		return 1;
	}

	vector<int> v;
	int k=sqrt(i);

	for(int j=2;j<=k;j++) {
		if(i%j==0) {
			if(A[i/j]==0 || A[j]==0) {
				A[i]=1;
				return 1;
			}

			if(A[j]==-1)
				v.push_back(j);
			if(A[i/j]==-1)
				v.push_back(i/j);
		}
	}

	if(A[i-1]==-1)
		v.push_back(i-1);

	for(int j=0;j<v.size();j++) {
		if(solve(v[j])==0) {
			A[i]=1;
			return 1;
		}
	}

	A[i]=0;
	return A[i];
}
int main() {
	memset(A,-1,sizeof A);
	A[1]=0;
	A[2]=1;
	A[3]=0;

	inp(t);

	while(t--) {
		inp(n);
		if(solve(n))
			printf("Mike\n");
		else
			printf("Tom\n");
	}
	return 0;
}
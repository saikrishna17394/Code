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

#define mod 1000000009
#define inf 1999999999
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n;
pair<ii,int> A[lim];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		int sm=inf,big=-inf;
		for(int i=0;i<n;i++) {
			ii p;
			inp(p.first);
			inp(p.second);
			A[i]=make_pair(p,i+1);
			sm=min(sm,p.second);
			big=max(big,p.second);
		}

		sort(A,A+n);

		ii p=A[0].first;

		if(p.second==sm) {
			printf("1\n");
			printf("%d NE\n",A[0].second);
			continue;
		}

		int cur=A[0].second;
		for(int i=1;i<n;i++) {
			if(A[i].first.first==A[0].first.first) {
				p=A[i].first;
				cur=A[i].second;
			}
			else
				break;
		}

		if(p.second==big) {
			printf("1\n");
			printf("%d SE\n",cur );
			continue;
		}

		p=A[n-1].first;

		if(p.second==big) {
			printf("1\n");
			printf("%d SW\n",A[n-1].second);
			continue;
		}

		cur=A[n-1].second;

		for(int i=n-2;i>=0;i--) {
			if(A[i].first.first==A[n-1].first.first) {
				p=A[i].first;
				cur=A[i].second;
			}
			else
				break;
		}

		if(p.second==sm) {
			printf("1\n");
			printf("%d NW\n",cur );
			continue;
		}


		if(A[1].first.second>=A[0].first.second) {
			printf("2\n");
			printf("%d NE\n",A[0].second );
			printf("%d SE\n",A[1].second );
		}
		else {
			printf("2\n");
			printf("%d SE\n",A[0].second );
			printf("%d NE\n",A[1].second );

		}

	}

	return 0;
}
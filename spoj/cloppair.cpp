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
#define x first
#define y second
#define mod 1000000007
#define inf 99999999999999
#define eps 1e-9
using namespace std;

typedef pair<lli,lli> ii;
inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

inline lli dist(ii a) {
	return a.x*a.x+a.y*a.y;
}

inline lli sq(lli n) {
	return n*n;
}

struct cmp {
	bool operator () (ii a,ii b) {
		return a.y<b.y;
	}
};

int main() {
	lli n,best=9,val;

	for(int i=1;i<14;i++) {
		best*=10;
		best+=9;
	}

	ii A[50000];

	set<ii,cmp> box;
	map<ii,int> m;
	int a,b;

	double ans,best1;

	inp(n);

	for(int i=0;i<n;i++) {
		inp(A[i].x);
		inp(A[i].y);
		m[A[i]]=i;
	}

	sort(A,A+n);
	box.insert(A[0]);
	int left=0;
	best1=sqrt(best);

	for(int i=1;i<n;i++) {
		while(left<i && (A[i].x-A[left].x)>best1)
			box.erase(A[left++]);

		for(set<ii>::iterator it=box.lower_bound(ii(A[i].x-best1,A[i].y-best1));it!=box.end();it++) {
			if(A[i].y+best1<it->y)
			 	break;

			val=sq(A[i].x-it->x)+sq(A[i].y-it->y);

			if(val<best) {
				best=min(best,val);
				best1=sqrt(best);
				a=m[*it];
				b=m[A[i]];
			}
		}

		box.insert(A[i]);
	}


	if(a>b)
		swap(a,b);
	printf("%d %d %.6f\n", a,b,best1);

	return 0;
}

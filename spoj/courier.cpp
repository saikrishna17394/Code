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
int t,n,m1,home,A[101][101],ans,z;
int x,y;

map<vector<int>,int> m;
int src[6],dest[6];

int dp_find(vector<int> v) {

	if(m.find(v)!=m.end())
		return m[v];

	int res=inf;

	vector<int> v1;


	for(int i=1;i<=z;i++) {
		if(v[i]>0) {
			v1=v;
			v1[0]=dest[i];
			v1[i]--;
			res=min(res,A[v[0]][src[i]]+A[src[i]][dest[i]]+dp_find(v1));
		}

	}
	if(res==inf) {
		res=A[v[0]][home];
	}


	m[v]=res;

	return res;
}

int main() {

	inp(t);

	while(t--) {
		inp(n);
		inp(m1);
		inp(home);

		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++)
				A[i][j]=inf;
			A[i][i]=0;
		}

		while(m1--) {
			inp(x);
			inp(y);
			inp(A[x][y]);
			A[y][x]=A[x][y];
		}

		for(int k=1;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++)
					A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
			}
		}

		inp(z);

		m.clear();

		vector<int> v(z+1,0);

		v[0]=home;

		for(int i=1;i<=z;i++) {
			inp(src[i]);
			inp(dest[i]);
			inp(v[i]);
		}

		printf("%d\n",dp_find(v));
	}

	return 0;
}
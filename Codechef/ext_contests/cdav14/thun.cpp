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

#define mod 1008
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n;
int A[15][15];

int main() {
	cin>>n;

	int num=1;

	vector<int> v;

	int l=0,r=n-1;

	for(int i=0;i<n;i++) {
		if(i%2==0) {
			v.push_back(l);
			l++;
		}
		else {
			v.push_back(r);
			r--;
		}
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			A[v[i]][j]=num++;
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(j>0)
				printf("*");
			printf("%d",A[i][j] );
		}
		printf("\n");
	}

	return 0;
}
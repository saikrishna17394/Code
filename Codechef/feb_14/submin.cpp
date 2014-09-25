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

int main() {
	int n,A[50],q,k;
	inp(n);
	map<int,int> m;
	for(int i=0;i<n;i++)
		inp(A[i]);

	for(int i=0;i<n;i++) {
		int val=A[i];
		m[val]++;
		for(int j=i+1;j<n;j++) {
			val=min(val,A[j]);
			m[val]++;
		}
	}

	inp(q);

	while(q--) {
		inp(k);
		if(m.find(k)==m.end())
			printf("0\n");
		else
			printf("%d\n", m[k]);
	}

	return 0;
}
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

int A[100000];
int n,c;

int main() {
	inp(n);
	inp(c);

	for(int i=0;i<n;i++)
		inp(A[i]);

	sort(A,A+n);

	int l=0,r=mod;


	while(l<r) {
		int m=(l+r)/2;
		m++;

		int idx=1;

		int prev=A[0];

		for(int i=1;i<n;i++) {
			if((A[i]-prev)>=m) {
				idx++;
				prev=A[i];
			}
		}

		if(idx>=c)
			l=m;
		else
			r=m-1;
	}

	cout<<l<<endl;
	return 0;
}
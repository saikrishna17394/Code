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
int n,A[100000];
map<int,int> m;


int main() {
	inp(n);

	for(int i=0;i<n;i++)
		inp(A[i]);
	m[A[0]]=1;

	int sum=A[0];

	for(int i=1;i<n;i++) {
		sum+=A[i];
		m[sum]=1;
	}

	int val=0;

	for(int i=0;i<n;i++) {
		val+=A[i];
		m.erase(m.begin());

		int idx=1;

		while(1) {
			if(val*idx==sum) {
				printf("%d ",val);
				break;
			}
			if(m.find(val*(idx+1))==m.end())
				break;
			idx++;
		}
	}

	printf("\n");

	return 0;
}
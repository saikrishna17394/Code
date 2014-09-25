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
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
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
int t,n,m,A[401],next[401],B[401];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=1;i<401;i++)
			B[i]=inf;

		for(int i=0;i<m;i++) {
			inp(A[i]);
		}

		for(int i=m-1;i>=0;i--) {
			next[i]=B[A[i]];
			B[A[i]]=i;
		}

		map<int,int> M;
		int ans=0;

		for(int i=0;i<m;i++) {
			if(M.find(A[i])!=M.end()) {
				M[A[i]]=next[i];
			}
			else if(M.size()<n) {
				M[A[i]]=next[i];
				ans++;
			}
			else {
				ans++;
				int val=-1,num;
				for(map<int,int>::iterator it=M.begin();it!=M.end();it++) {
					if(it->second>val) {
						val=it->second;
						num=it->first;
					}
				}
				M.erase(num);
				M[A[i]]=next[i];
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
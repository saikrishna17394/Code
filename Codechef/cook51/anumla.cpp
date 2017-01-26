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

int A[1<<15],B[1<<15];

int main() {
	int t,n,num;

	inp(t);

	while(t--) {
		inp(n);
		int lim=1<<n;

		// cout<<n<<" "<<lim<<endl;
		for(int i=0;i<lim;i++) {
			inp(A[i]);
		}
		
		
		vector<int> ans;
		sort(A,A+lim);
		ans.clear();
		ans.push_back(A[1]);

		for(int a=1;a<n;a++) {
			int idx=0;
			map<int,int> m;
			m.clear();

			for(int i=0;i<lim;i++) {
				if(m.find(A[i])==m.end()) {
					m[A[i]+A[1]]++;
					B[idx++]=A[i];
				}
				else {
					if(m[A[i]]>0)
						m[A[i]]--;
					else {
						B[idx++]=A[i];
						m[A[i]+A[1]]++;
					}
				}
			}
			// sort(B,B+idx);
			for(int i=0;i<idx;i++)
				A[i]=B[i];
			ans.push_back(A[1]);
			lim/=2;
		}
		for(int i=0;i<n;i++) {
			printf("%d ",ans[i] );
		}
		printf("\n");
	}

	return 0;
}
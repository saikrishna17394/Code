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

int t,n,m,c,A[100001],B[100000],C[100001];

queue<ii> q;

int main() {

	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(c);
		int l,r;
		l=1;
		r=m;
		for(int i=0;i<m;i++) {
			inp(B[i]);
		}


		while(l<=r) {
			memset(A,-1,sizeof A);
			memset(C,0,sizeof C);
			// cout<<l<<" "<<r<<endl;
			int mid=(l+r)/2,val=0,sz=0;

			while(!q.empty())
				q.pop();

			for(int i=0;i<m;i++) {
				if(C[B[i]]) {
					q.push(ii(B[i],i));
					A[B[i]]=i;
					continue;
				}

				if(sz<mid) {
					q.push(ii(B[i],i));
					val++;
					A[B[i]]=i;
					sz++;
					C[B[i]]=1;
					continue;
				}

				while(1) {
					ii p=q.front();
					q.pop();
					if(A[p.first]==p.second) {
						C[p.first]=0;
						break;
					}
				}
				q.push(ii(B[i],i));
				val++;
				A[B[i]]=i;
				C[B[i]]=1;
			}

			// cout<<mid<<" "<<val<<endl;
			if(l==r) {
				if(val>c)
					printf("-1\n");
				else
					printf("%d\n", l);
				break;
			}
			// cout<<mid<<" "<<val<<endl;
			if(val>c)
				l=mid+1;
			else
				r=mid;
		}
	}

	return 0;
}
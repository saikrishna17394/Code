#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int t,n,A[50],B[50],P[50];

	double dp[16][17],p[50],ans;

	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(P[i]);
			inp(A[i]);
			inp(B[i]);
			p[i]=P[i]/100.0;
		}

		if(n>16) {
			printf("0\n");
			continue;
		}

		if(n==1) {
			printf("1\n");
			continue;
		}

		int num=1<<n,n1;
		ans=0;
		for(int i=0;i<num;i++) {
			int val=0;
			double prob;
			n1=i;
			set<int> s;

			for(int j=n-1;j>=0;j--) {
				if(j==n-1) {
					if(n1&1) {
						s.insert(A[j]);
						prob=p[j];
					}
					else {
						s.insert(B[j]);
						prob=1.0-p[j];
					}
					n1/=2;
					continue;
				}
				if(n1&1) {
					s.insert(A[j]);
					prob*=p[j];
				}
				else {
					s.insert(B[j]);
					prob*=(1.0-p[j]);
				}
				n1/=2;
			}

			// cout<<i<<" "<<s.size()<<" "<<prob<<endl;
			if(s.size()==n)
				ans+=prob;
			// cout<<ans<<endl;
		}
		printf("%.7f\n",ans);
	}

	return 0;
}
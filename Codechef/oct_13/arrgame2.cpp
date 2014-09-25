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
#define eps 1e-9
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
	int t,n,num;
	double A[100000],B[100000],ans;
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(num);
			A[i]=log(num)/(double)num;
			// cout<<num<<" " <<A[i]<<endl;
		}
		for(int i=0;i<n;i++) {
			inp(num);
			B[i]=log(num)/(double)num;
			// cout<<num<<" "<<B[i]<<endl;
		}

		ans=0;
		sort(A,A+n);
		sort(B,B+n);
		int j=0;
		for(int i=0;i<n;i++) {
			while(j<n) {
				if(B[j]>=A[i])
					break;
				j++;
			}
			ans+=(double)j/(double)n;
			// cout<<j<<" "<<n<<" ";
			// cout<<ans<<endl;
		}
		printf("%.6f\n", ans);
	}

	return 0;
}
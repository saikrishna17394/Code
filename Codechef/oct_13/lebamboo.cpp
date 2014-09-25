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


int main() {
	int t,n,A[50],B[50],sum1,sum2,val,d,x,kri,ans;

	inp(t);

	while(t--) {
		inp(n);
		sum1=sum2=0;
		kri=0;
		for(int i=0;i<n;i++) {
			inp(A[i]);
			sum1+=A[i];
		}

		for(int i=0;i<n;i++) {
			inp(B[i]);	
			sum2+=B[i];
		}

		if(n==1) {
			if(sum1<sum2)
				printf("-1\n");
			else
				printf("%d\n",sum1-sum2);
			continue;
		}
		if(n==2) {
			if(sum1==sum2)
				printf("%d\n",abs(A[0]-B[0]));
			else
				printf("-1\n");
			continue;
		}

		if(sum2<sum1) {
			printf("-1\n");
			continue;
		}
		val=sum2-sum1;

		if(val%(n-2)!=0) {
			printf("-1\n");
			continue;
		}

		val/=(n-2);
		ans=val;
		for(int i=0;i<n;i++) {
			d=B[i]-A[i]-(ans-val);
			x=(val-d)/2;

			if(val<d || (val-d)%2==1 || x>val) {
				printf("-1\n");
				kri=-1;
				break;
			}
			val-=x;
		}
		if(kri==-1)
			continue;
		printf("%d\n", ans);
	}

	return 0;
}
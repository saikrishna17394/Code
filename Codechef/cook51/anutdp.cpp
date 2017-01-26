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
#define lim 100000000

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,l,r,n;
lli dp[40];
int A[lim+1]={0};
lli B[43816];
int C[lim+1];

map<int,int> m;

int main() {

	dp[1]=1;
	dp[2]=1;

	for(int i=3;i<40;i++) {
		dp[i]=dp[i-1]+dp[i-2];
		m[(int)dp[i]]=i;
		if(dp[i]>lim)
			break;
		// cout<<i<<" "<<dp[i]<<endl;
	}
	int idx=0;

	for(int i=39;i>2;i--) {

		lli num=dp[i];
		int cnt=idx;
		while(1) {
			if(num>lim)
				break;
			if(A[num]==0)
				B[idx++]=num;
			A[num]=(int)dp[i];
			// int cnt=idx;
			for(int j=0;j<cnt;j++) {
				if((num*B[j])>lim)
					continue;
				if(A[num*B[j]]==0)
					B[idx++]=num*B[j];
				A[num*B[j]]=(int)dp[i];
			}
			num*=dp[i];
			// cout<<"what "<<num<<endl;
		}
		sort(B,B+idx);
		// cout<<idx<<endl;
	}
	A[0]=1;
	A[1]=1;

	C[0]=1;

	// for(int i=0;i<10;i++)
	// 	cout<<i<<" "<<A[i]<<endl;
	for(int i=1;i<=lim;i++)
		C[i]=C[i-1]+(A[i]>0);

	inp(t); 
	// t=0;
	while(t--) {
		inp(l);
		inp(r);
		inp(n);

		lli left=l;
		
		int val;
		while(l<=r) {
			int mid=(l+r)/2;

			val=C[mid];
			if(left>0)
				val-=C[left-1];

			if(l==r)
				break;
			if(val>=(int)n)
				r=mid;
			else
				l=mid+1;
		}
		if(val==(int)n) {
			printf("%lld ",l );
			if(l==0)
				printf("#\n");
			else if(l==1)
				printf(".\n");
			else {
				int num=(int)l;
				while(num>1) {
					int wow=m[A[num]];
					// cout<<num<<" "<<A[num]<<" "<<wow<<endl;
					for(int i=0;i<wow;i++)
						printf(".");
					num/=A[num];
					if(num>1)
						printf("#");
				}
				printf("\n");
			}
		}
		else
			printf("-1\n");
	}


	return 0;
}
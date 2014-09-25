#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
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
	int t,n,A[65],num,ans,c,r,B[65];
	inp(t);
	while(t--) {
		inp(n);

		memset(A,-1,sizeof A);

		for(int i=0;i<32;i++) {
			A[i*2+1]=n&1;
			n>>=1;
		}

		// for(int i=0;i<65;i++)
		// 	cout<<A[i]<<" ";
		// cout<<endl;
		B[0]=0;
		B[1]=1;
		c=1;
		r=2;

		for(int i=2;i<65;i++) {
			// cout<<i<<" "<<r<<" : \n";
			// cout<<r<<" "<<c<<" "<<i+B[2*c-i]<<endl;
			if(i>r || i+B[c-(i-c)]>=r) {
				// cout<<"kri\n";
				c=i;
				B[i]=0;
				for(int j=i+1;j<65 && (2*i-j)>=0;j++) {
					// cout<<"man\n";

					//cout<<j<<" "<<
					if(A[j]==A[2*i-j]) {
						r=j;
						B[i]++;
					}
					else
						break;
				}
			}
			else
				B[i]=B[c-(i-c)];

			// cout<<i<<" "<<B[i]<<endl;
		}

		ans=0;

		for(int i=0;i<65;i++) {
			ans=max(ans,B[i]);
		}

		printf("%d\n",ans);

	}

	return 0;
}
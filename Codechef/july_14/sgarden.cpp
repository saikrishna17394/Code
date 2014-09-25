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
#define lim 100001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int t,n,A[100001],prime[100001]={0},pow1[100001],vis[100001];

lli ans;

int main() {
	inp(t);

	for(int i=2;i*i<lim;i++) {
		if(prime[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				prime[j]=i;
		}
	}


	while(t--) {
		inp(n);

		memset(pow1,0,sizeof pow1);
		ans=1;

		for(int i=1;i<=n;i++)
			inp(A[i]);

		memset(vis,0,sizeof vis);


		// printf("man\n");
		for(int i=1;i<=n;i++) {
			if(vis[i]==0) {
				int idx=A[i],num=1;
				while(idx!=i) {
					vis[idx]=1;
					idx=A[idx];
					num++;
				}

				while(1) {

					int val=0,fac=prime[num];

					if(fac==0) {
						pow1[num]=max(pow1[num],1);
						break;
					}

					while(num%fac==0) {
						num/=fac;
						val++;
					}
					pow1[fac]=max(pow1[fac],val);

					if(num==1) 
						break;
				}
			}
		}

		for(int i=2;i<=n;i++) {
			while(pow1[i]) {
				ans=ans*(lli)i;
				ans%=mod;
				pow1[i]--;
			}
		}

		printf("%lld\n", ans);
	}


	return 0;	
}
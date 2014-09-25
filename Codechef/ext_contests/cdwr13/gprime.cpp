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
#define lim 10000001
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int prime[lim]={0},k,t,n,cnt[lim],num,val;
lli ans[lim];

int main() {

	k=sqrt(lim);

	for(int i=2;i<=k;i++) {
		if(prime[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				prime[j]=i;
		}
	}


	cnt[1]=1;

	for(int i=2;i<lim;i++) {
		if(prime[i]==0)
			cnt[i]=i-1;
		else {
			num=i;
			val=1;

			cnt[i]=1;
			while(num%prime[i]==0) {
				num/=prime[i];
				cnt[i]*=prime[i];
			}
			cnt[i]/=prime[i];
			cnt[i]*=(prime[i]-1);
			cnt[i]*=cnt[num];
		}
	}

	ans[0]=0;
	ans[1]=3;
	ans[2]=1;
	for(int i=3;i<lim;i++) {
		ans[i]=(lli)(cnt[i])+ans[i-1];
	}

	// cout<<ans[6]<<" "<<cnt[6]<<endl;
	inp(t);

	while(t--) {
		inp(n);

		if(n<3)
			printf("%lld\n",ans[n-1]);
		else
			printf("%lld\n",2*ans[n-1]+3);
	}

	return 0;
}
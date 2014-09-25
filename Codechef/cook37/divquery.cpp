#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
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

int n,q,A[100001],B[101][100001]={0},a,b,k1,ans;

int box(int i) {
	int val=i/1000;
	if(i%1000==0)
		return val;
	val++;
	return val;
}


int main() {
	inp(n);
	inp(q);
	for(int i=1;i<=n;i++)
		inp(A[i]);

	for(int k=1;k<=100000;k++) {
		for(int i=1;i<=n/1000;i++) {
			int val=0,ind=(i-1)*1000;
			for(int j=1;j<=1000;j++) {
				if(A[ind+j]%k==0)
					val++;
			}
			B[i][k]=val;
		}
		int ind=(n/1000),ran=n%1000;
		int val=0;
		for(int i=1;i<=ran;i++) {
			if(A[ind*1000+i]%k==0)
				val++;
		}
		if(ran!=0)
			B[ind+1][k]=val;
	}

	while(q--) {
		inp(a);
		inp(b);
		inp(k1);

		ans=0;

		int l=box(a),r=box(b);

		if(l==r) {
			for(int i=a;i<=b;i++) {
				if(A[i]%k1==0)
					ans++;
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=l+1;i<=r-1;i++)
			ans+=B[i][k1];

		if(a%1000==1)
			ans+=B[l][k1];
		else {
			for(int i=a;i<=l*1000;i++) {
				if(A[i]%k1==0)
					ans++;
			}
		}

		if(b%1000==0)
			ans+=B[r][k1];
		else {
			for(int i=(r-1)*1000+1;i<=b;i++) {
				if(A[i]%k1==0)
					ans++;
			}			
		}
		printf("%d\n", ans);
	}

	return 0;
}
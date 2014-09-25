#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

inline lli pow(lli a,lli n,lli m) {
	lli result =1;
	while(n!=0) {
		//cout<<n<<endl;
		if(n&1)
			result=(result*a)%m;
		a=(a*a)%m;
		n=n>>1;
	}
	return result;
}

int n,num,t,l,r,m;
int A[100001][25]={0};
lli ans;
int B[101]={0},primes[25],ind[101],cnt=0;

int D[101][25]={0};

int main() {

	for(int i=2;i<10;i++) {
		if(B[i]==0) {
			for(int j=i*i;j<=100;j+=i)
				B[j]=i;
			//cnt++;
		}
	}

	cnt=0;
	for(int i=2;i<101;i++) {
		if(B[i]==0) {
			primes[cnt++]=i;
			ind[i]=cnt-1;
		}
	}

	for(int i=2;i<101;i++) {
		num=i;
		while(B[num]!=0) {
			D[i][ind[B[num]]]++;
			num/=B[num];
		}
		D[i][ind[num]]++;
	}
	//cout<<cnt<<endl;
	inp(n);

	for(int i=1;i<=n;i++) {
		inp(num);
		for(int j=0;j<25;j++)
			A[i][j]=A[i-1][j];

		for(int j=0;j<25;j++)
			A[i][j]+=D[num][j];
		//A[i][C[i]]++;
	}

	inp(t);

	while(t--) {
		inp(l);
		inp(r);
		inp(m);
		
		ans=1;

		for(int j=0;j<25;j++)
			ans=(ans*pow((lli)primes[j],(lli)(A[r][j]-A[l-1][j]),(lli)m))%(lli)m;
		printf("%lld\n",ans);
	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define x getchar_unlocked()
#define lim 1000200
using namespace std;
 
inline void inp(int &n ) {//fast input function
    n=0;
    int ch=x,sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=x;
    n=n*sign;
}

lli pow(lli a,lli n,lli m) {
	lli result=1;
	while(n>0) {
		if(n&1)
			result=(result*a)%m;
		a=(a*a)%m;

		n=n>>1;
	}
	return result;
}

int B[lim+1];
lli A[1000200];
lli cnt=0;long long int ans=0,s;

int main() {

	lli k=sqrt(lim);

	for(lli i=2;i<=k;i++) {
		if(B[i]==0) {
			for(lli j=i*i;j<=lim;j+=i)
				B[j]=i;
		}
	}

	for(lli i=2;i<=lim;i++)
		if(B[i]==0)
			A[cnt++]=i;


	lli val=10,rem,quo;
	cout<<A[cnt-1]<<endl;
	for(int i=2;A[i]<1000000;i++) {
		if(A[i]>val)
			val*=10;

		s=A[i];
		rem=val%A[i+1];

		quo=(A[i+1]-A[i])%A[i+1];

		quo=(quo*pow(rem,A[i+1]-2,A[i+1]))%A[i+1];

		s+=val*quo;

		if(A[i]==19) {
			cout<<s<<endl;
			cout<<val<<endl;
			cout<<quo<<endl;
			cout<<A[2]<<endl;
		}
		ans+=s;
		if(ans<0 || s<0)
			cout<<"shout\n";

	}

	cout<<ans<<endl;
	return 0;
}
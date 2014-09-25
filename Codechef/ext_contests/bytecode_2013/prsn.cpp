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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

lli t,m,z,A[10001],ans,num,val;

lli cut(lli i,lli j) {
	//cout<<i<<" "<<j<<endl;
	lli ans1=0;
	if(i>j)
		return 0;

	lli l=(i+j)/2,r=(i+j+1)/2;
	lli ind=-1;
	for(;l>=i;l--,r++) {
		if(A[l]==1 && A[r]==1) {
		 	ans1=min(cut(i,l-1)+cut(l+1,j),cut(i,r-1)+cut(r+1,j));
		 	return ans1;
		 }
		if(A[l]==1) {
			ind=l;
			break;
		}
		if(A[r]==1) {
			ind=r;
			break;
		}
	}

	if(ind==-1)
		return 0;

	//A[ind]=2;
	for(int a=ind-1;a>=i;a--) {
		//if(A[a]==2)
		//	break;
		ans1++;
	}

	for(int a=ind+1;a<=j;a++) {
		if(A[a]==2)
			break;
		ans1++;
	}

	//cut(i,ind-1);
	//cut(ind+1,j);
	return ans1+cut(i,ind-1)+cut(ind+1,j);
}

int main() {
	inp(t);
	while(t--) {
		inp(m);
		inp(z);

		memset(A,0,sizeof A);

		for(int i=1;i<=z;i++) {
			inp(num);
			A[num]=1;
		}

		ans=0;
		//cut(1,m);
		printf("%lld\n", cut(1,m));
	}

	return 0;
}
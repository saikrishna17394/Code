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

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli ans[300][9],n,t,A[300][3];

lli min1(lli a,lli b,lli c) {
	lli val=min(a,b);
	val=min(val,c);
	return val;
}

lli max1(lli a,lli b,lli c) {
	lli val=max(a,b);
	val=max(val,c);
	return val;
}

lli fun0(lli i) {
	if(i>=n)
		return inf;

	lli ret=ans[i][0];

	if(ret!=-1)
		return ret;
	ret=inf;

	vector<int> v;
	for(int j=0;j<3;j++) {
		v.push_back(A[i][j]);
	}
	sort(v.begin(),v.end());

	if(i==(n-1)) {
		ret=v[2]-v[0];
		ans[i][0]=ret;
		return ret;
	}

	ret=min(ret,v[2]-v[0]+fun0(i+1));
	lli num1,num2;

	if(i<=(n-3)) {
		num1=min1(A[i][0],A[i+1][0],A[i+2][0]);
		num2=max1(A[i][0],A[i+1][0],A[i+2][0]);
		ret=min(ret,num2-num1+fun1(i));

		num1=min1(A[i][2],A[i+1][2],A[i+2][2]);
		num2=max1(A[i][2],A[i+1][2],A[i+2][2]);
		ret=min(ret,num2-num1+fun2(i));		
	}

	if(i<=(n-2)) {
		num1=min1(A[i][0],A[i][1],A[i+1][1]);
		num2=max1(A[i][0],A[i][1],A[i+1][1]);

		ret=min(ret,num2-num1+fun3(i));

		num1=min1(A[i][1],A[i][2],A[i+1][2]);
		num2=max1(A[i][1],A[i][2],A[i+1][2]);

		ret=min(ret,num2-num1+fun4(i));

		num1=min1(A[i][0],A[i][1],A[i+1][0]);
		num2=max1(A[i][0],A[i][1],A[i+1][0]);

		ret=min(ret,num2-num1+fun5(i));

		num1=min1(A[i][1],A[i][2],A[i+1][1]);
		num2=max1(A[i][1],A[i][2],A[i+1][1]);

		ret=min(ret,num2-num1+fun6(i));

	}
	ans[i][0]=ret;
	return ret;
}

lli fun1(lli i) {
	if(i>(n-3))
		return inf;

	lli ret=ans[i][1];

	if(ret!=-1)
		return ret;

	ret=inf;

	lli num1,num2,num3,num4;
	ret=inf;

	num1=min1(A[i][1],A[i][2],A[i+1][2]);
	num2=max1(A[i][1],A[i][2],A[i+1][2]);
	ret=min(ret,num2-num1+fun7(i+1));


	num1=min1(A[i][1],A[i+1][1],A[i+2][1]);
	num2=max1(A[i][1],A[i+1][1],A[i+2][1]);

	num3=min1(A[i][2],A[i+1][2],A[i+2][2]);
	num4=max1(A[i][2],A[i+1][2],A[i+2][2]);

	ret=min(ret,num2-num1+num4-num3+fun0(i+3));

	num1=min1(A[i][1],A[i][2],A[i+1][1]);
	num2=max1(A[i][1],A[i][2],A[i+1][1]);
	ret=min(ret,num2-num1+fun5(i+1));

	ans[i][1]=ret;
	return ret;
}

lli fun2(lli i) {
	if(i>(n-3))
		return inf;

	lli ret=ans[i][2];

	if(ret!=-1)
		return ret;

	ret=inf;

	lli num1,num2,num3,num4;
	ret=inf;

	num1=min1(A[i][0],A[i][1],A[i+1][1]);
	num2=max1(A[i][0],A[i][1],A[i+1][1]);
	ret=min(ret,num2-num1+fun4(i+1));

	num1=min1(A[i][0],A[i][1],A[i+1][0]);
	num2=max1(A[i][0],A[i][1],A[i+1][0]);
	ret=min(ret,num2-num1+fun8(i+1));

	num1=min1(A[i][1],A[i+1][1],A[i+2][1]);
	num2=max1(A[i][1],A[i+1][1],A[i+2][1]);

	num3=min1(A[i][0],A[i+1][0],A[i+2][0]);
	num4=max1(A[i][0],A[i+1][0],A[i+2][0]);

	ret=min(ret,num2-num1+num4-num3+fun0(i+3));

	ans[i][2]=ret;
	return ret;
}

lli fun3(lli i) {
	if(i>(n-3))
		return inf;

	lli ret=ans[i][3];

	if(ret!=-1)
		return ret;

	ret=inf;

	lli num1,num2,num3,num4;
	ret=inf;

	num1=min1(A[i][2],A[i+1][2],A[i+2][2]);
	num2=max1(A[i][2],A[i+1][2],A[i+2][2]);
	ret=min(ret,num2-num1+fun4(i+1));

	ans[i][3]=ret;
	return ret;
}

lli fun4(lli i) {
	if(i>(n-2))
		return inf;

	lli ret=ans[i][4];

	if(ret!=-1)
		return ret;

	ret=inf;

	lli num1,num2,num3,num4;
	ret=inf;

	num1=min1(A[i][2],A[i+1][2],A[i+2][2]);
	num2=max1(A[i][2],A[i+1][2],A[i+2][2]);
	ret=min(ret,num2-num1+fun4(i+1));

	ans[i][4]=ret;
	return ret;

}
int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(int i=0;i<n;i++) {
			for(int j=0;j<3;j++)
				inp(A[i][j]);
		}
		memset(A,-1,sizeof A);

		printf("%lld\n",fun0(0));
	}

	return 0;
}
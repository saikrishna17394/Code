#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli k;
	string s;
	inp(k);
	cin>>s;
	lli num=0,num1,len=s.length();
	for(int i=0;i<len;i++)
		if(s[i]=='1')
			num++;

	num1=len-num;

	if(2*num1<=3*num)
		printf("%lld\n",k*len);
	else if(num==0)
		printf("0\n");
	else
		printf("10\n");
	return 0;
}
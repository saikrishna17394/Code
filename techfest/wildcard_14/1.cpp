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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli num;
	lli cnt=0,ans=0;
	int lim=100000;
	for(lli i=1;i<=lim;i++) {
		num=i*(lli)6;
		num+=i*i*(lli)15;
		num+=i*i*i*(lli)8;
		num-=1;
		if(num%27!=0)
			continue;
		num/=27;
		for(lli j=1;j*j<=num;j++) {
			if((i+j)>lim)
				break;
			lli val=j*j;
			if(num%val==0 && (i+j+(num/val))<=lim) {
				ans++;
			}
		}
	}
	cout<<lim<<" "<<ans<<endl;
	return 0;
}
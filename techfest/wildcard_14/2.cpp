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
#define lim 1000004
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int ans[10];
int A[10];
bool check(int n,int d) {
	for(int i=0;i<d;i++) {
		A[i]=n%10;
		n/=10;
	}

	int num,cnt=0;
	for(int i=d-1;i>=0;i--) {
		num=0;
		for(int j=i;j>=0;j--) {
			num=num*10;
			num+=A[j];
			if(num%d==0)
				cnt++;
		}
	}
	if(cnt==1)
		return true;
	return false;
}
int main() {
	ans[1]=9;
	int val=10,val1=100;

	for(int i=2;i<9;i++) {
		ans[i]=ans[i-1];
		for(int j=val;j<val1;j++) {
			if(check(j,i))
				ans[i]++;
		}
		cout<<i<<" "<<ans[i]<<" "<<endl;
		val*=10;
		val1*=10;
	}
	return 0;
}
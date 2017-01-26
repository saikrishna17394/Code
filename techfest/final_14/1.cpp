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

#define mod 1000000003
#define inf 999999999
#define lim 200100
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int A[lim+1]={0};
lli B[lim],cnt=0;
bool check(lli n) {
	int num;
	bool ok=false;

	for(int i=0;B[i]*B[i]<=n;i++) {
		if(n%B[i]==0) {
			num=0;
			while(n%B[i]==0) {
				num++;
				n/=B[i];
			}
			if(num==1)
				return false;
			if(num&1)
				ok=true;
		}
	}

	if(n>1)
		return false;
	if(ok)
		return true;
	return false;
}

int main() {

	for(int i=2;i*i<lim;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=i;
		}
	}

	for(lli i=2;i<lim;i++)
		if(A[i]==0)
			B[cnt++]=i;

	cout<<"dude\n";
	cout<<cnt<<" "<<B[cnt-1]<<endl;

	for(lli i=400;i<=10000000000;i+=4) {
		// cout<<i<<endl;
		if(check(i) && check(i+1)) 
			cout<<i<<"  "<<i+1<<endl;
		if(check(i) && check(i-1))
			cout<<i<<" "<<i-1<<endl;
	}


	return 0;
}
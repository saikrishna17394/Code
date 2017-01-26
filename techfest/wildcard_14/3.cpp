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

int A[lim]={0};
int B[lim],cnt=0;

int main() {

	for(int i=2;i*i<lim;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=1;
		}
	}

	for(int i=2;i<lim;i++) {
		if(A[i]==0) 
			B[cnt++]=i;
	}
	cout<<cnt<<" "<<B[cnt-1]<<endl;
	bool ok=false;
	int num=0;
	for(int i=1;;i++) {
		for(int j=1;j<=i;j++) {
			num++;
			if(num==cnt) {
				cout<<i<<" "<<j<<" "<<i+j<<endl;
				ok=true;
				break;
			}
		}
		if(ok)
			break;
	}
	return 0;
}
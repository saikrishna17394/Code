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
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf (lli)1e16
#define lim 100001

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[10]={119,36,93,109,46,107,123,37,127,111},t,s,m;

int B[8][10],dp[8];

int len(int num) {
	if(num==0)
		return 1;
	int ret=0;
	while(num>0) {
		ret++;
		num/=10;
	}
	return ret;
}

int pos(int num,int i) {
	for(int j=0;j<i;j++) {
		num/=10;
	}
	return num%10;
}

int lar(int,int);

int solve(int i,int b) {
	// cout<<i<<" "<<b<<" "<<endl;
	if(i==0) {
		for(int j=b;j>=0;j--) {
			if(B[i][j]==1) {
				return j;
			}
		}
		return -1;
	}


	int val=1;
	for(int j=0;j<i;j++)
		val*=10;

	// cout<<"man "<<(b/val)*val<<endl;
	if(B[i][b/val]==1) {
		int ret=solve(i-1,b%val);
		if(ret!=-1) {
			// cout<<(b/val)*val<<" : oo\n";
			return (b/val)*val+ret;
		}
	}

	for(int j=b/val-1;j>=0;j--) {
		// cout<<i<<" "<<j<<" ww "<<B[i][j]<<endl;
		if(B[i][j]==1) {
			// cout<<j*val<<" :aa\n";
			return j*val+lar(i-1,b%val);
		}
	}

	return -1;
}

int lar(int i,int b) {
	int num=0;

	for(int j=i;j>=0;j--) {
		for(int k=9;k>=0;k--) {
			if(B[j][k]==1) {
				num*=10;
				num+=k;
				break;
			}
		}
	}
	// cout<<"lar "<<i<<" "<<b<<" "<<num<<endl;
	return num;
}
int main() {
	inp(t);

	int a,b;

	while(t--) {
		inp(a);
		inp(b);

		s=a;
		m=b;
		memset(B,0,sizeof B);
		// memset(dp,-1,sizeof dp);

		for(int i=0;i<8;i++) {
			int num=s%10;
			for(int j=0;j<10;j++) {
				if(s==0) {
					if(a==0) {
						if(i==0) {
							B[i][0]=1;
							B[i][8]=1;
						}
						else
							B[i][j]=1;
					}
					else
						B[i][j]=1;
					continue;
				}
				if((A[num]|A[j])==A[j])
					B[i][j]=1;
			}
			// cout<<i<<" : ";
			// for(int j=0;j<10;j++)
			// 	cout<<B[i][j]<<" ";
			// cout<<endl;
			s/=10;
		}
		s=a;
		m=b;
		printf("%d\n",solve(len(m)-1,m));
	}


	return 0;
}
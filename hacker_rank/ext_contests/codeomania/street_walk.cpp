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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n;
string s[1000];
int A[1000][1000];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			cin>>s[i];
		memset(A,-1,sizeof A);

		if(s[0][0]=='.')
			A[0][0]=1;

		for(int i=1;i<n;i++) {
			if(s[0][i]=='.')
				A[0][i]=A[0][i-1];
			if(s[i][0]=='.')
				A[i][0]=A[i-1][0];
		}

		for(int i=1;i<n;i++) {
			for(int j=1;j<n;j++) {
				if(s[i][j]=='.') {
					int val=0;
					bool ok=false;
					if(A[i-1][j]>=0) {
						val+=A[i-1][j];
						ok=true;
					}
					if(A[i][j-1]>=0) {
						val+=A[i][j-1];
						ok=true;
					}
					if(ok)
						A[i][j]=val%mod;
				}
			}
		}

		printf("%d\n", A[n-1][n-1]);
	}

	return 0;
}
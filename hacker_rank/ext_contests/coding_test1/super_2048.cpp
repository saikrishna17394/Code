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
#define lim 1000001

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,A[20][20];
string s;
vector<int> v,v1;

void solve() {
	int prev=-1;
	for(int i=0;i<v.size();i++) {
		if(v[i]==prev) {
			v1.push_back(2*v[i]);
			prev=-1;
		}
		else {
			if(prev!=-1)
				v1.push_back(prev);
			prev=v[i];
		}
	}
	if(prev!=-1)
		v1.push_back(prev);
}

int main() {
	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		cin>>s;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				inp(A[i][j]);

		if(s[0]=='r' || s[0]=='l') {
			for(int i=0;i<n;i++) {
				v.clear();
				v1.clear();

				if(s[0]=='r') {
					for(int j=n-1;j>=0;j--) {
						if(A[i][j]>0) {
							v.push_back(A[i][j]);
						}
						A[i][j]=0;
					}
					solve();
					for(int j=0;j<v1.size();j++) {
						A[i][n-j-1]=v1[j];
					}
				}
				else {
					for(int j=0;j<n;j++) {
						if(A[i][j]>0)
							v.push_back(A[i][j]);
						A[i][j]=0;
					}
					solve();
					for(int j=0;j<v1.size();j++)
						A[i][j]=v1[j];
				}
			}
		}
		else {
			for(int j=0;j<n;j++) {
				v.clear();
				v1.clear();

				if(s[0]=='u') {
					for(int i=0;i<n;i++) {
						if(A[i][j]>0)
							v.push_back(A[i][j]);
						A[i][j]=0;
					}
					solve();

					for(int i=0;i<v1.size();i++)
						A[i][j]=v1[i];
				}
				else {
					for(int i=n-1;i>=0;i--) {
						if(A[i][j]>0)
							v.push_back(A[i][j]);
						A[i][j]=0;
					}
					solve();

					for(int i=0;i<v1.size();i++)
						A[n-i-1][j]=v1[i];
				}
			}
		}
		printf("Case #%d:\n",a );
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				printf("%d ",A[i][j] );
			printf("\n");
		}
	}

	return 0;
}
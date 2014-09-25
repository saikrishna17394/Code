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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
string s[10];
int t,n,m,ans;

bool check(int j1,int j2) {
	// cout<<"dude\n";
	for(int i=0;i<n;i++) {
		if(s[i][j1]!=s[i][j2])
			return false;
	}
	return true;
}

int A[10][10][10][10][10][10];

int main() {
	inp(t);
	// cout<<"man\n";
	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<n;i++) {
			cin>>s[i];
		}
		ans=0;

		memset(A,0,sizeof A);
		// cout<<"dude\n";
		// cout<<n<< " "<<m<<endl;
		// return 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				for(int i1=0;i1<n;i1++) {
					for(int j1=0;j1<m;j1++) {
						// cout<<i<<" "<<j<<endl;
						if(i==i1 && j==j1)
							continue;
						if(s[i][j]==s[i1][j1]) {
							ans=1;
							A[i][j][i1][j1][0][0]=1;
						}
					}
				}
			}
		}
		// cout<<"dude\n";
		for(int l=1;l<m;l++) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<(m-l);j++) {

					for(int i1=0;i1<n;i1++) {
						for(int j1=0;j1<(m-l);j1++) {
							if(i==i1 && j==j1)
								continue;

							if(s[i][j]==s[i1][j1] && A[i][j+1][i1][j1+1][0][l-1]) {
								ans=l+1;
								A[i][j][i1][j1][0][l]=1;
							}

						}
					}
				}
			}
		}

		for(int l=1;l<n;l++) {
			for(int r=0;r<m;r++) {
				for(int i=0;i<(n-l);i++) {
					for(int j=0;j<(m-r);j++) {

						for(int i1=0;i1<(n-l);i1++) {
							for(int j1=0;j1<(m-r);j1++) {
								if(i==i1 && j==j1)
									continue;
								if(A[i][j][i1][j1][0][r] && A[i+1][j][i1+1][j1][l-1][r]) {
									ans=max(ans,(l+1)*(r+1));
									A[i][j][i1][j1][l][r]=1;
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
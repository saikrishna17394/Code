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

string A[100];
int t,n;

set<int> B[26];
set<int> C[26][26];
int dp[100];
string ans[100];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<26;i++) {
			B[i].clear();
			for(int j=0;j<26;j++)
				C[i][j].clear();
		}

		for(int i=0;i<n;i++) {
			cin>>A[i];

			for(int j=0;j<A[i].size();j++) {
				if(A[i][j]>='A' && A[i][j]<='Z')
					A[i][j]='a'+(A[i][j]-'A');
				B[A[i][j]-'a'].insert(i);
				if(j>0)
					C[A[i][j-1]-'a'][A[i][j]-'a'].insert(i);
			}
			ans[i]="";
		}

		memset(dp,0,sizeof dp);

		for(int i=0;i<26;i++) {
			int idx;
			if(B[i].size()==1) {
				idx=*B[i].begin();
				if(dp[idx]==0) {
					dp[idx]=1;
					ans[idx]+='a'+i;
				}
			}
		}
		
		for(int i=0;i<26;i++) {
			int idx;
			for(int j=0;j<26;j++) {
				if(C[i][j].size()==1) {
					idx=*C[i][j].begin();
					if(dp[idx]==0) {
						dp[idx]=1;
						ans[idx]+='a'+i;
						ans[idx]+='a'+j;
					}
				}
			}
		}

		for(int i=0;i<n;i++) {
			if(dp[i]==0)
				printf("IMPOSSIBLE\n");
			else
				cout<<ans[i]<<endl;
		}

	}

	return 0;
}
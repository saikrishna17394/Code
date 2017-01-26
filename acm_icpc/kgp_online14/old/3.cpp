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

int lps[1000000][2];
int A[1000100];
int ans;
void compute(string & pat,int );
void solve1(string& txt,string& pat,int idx);
void solve(string& txt,string& pat,int idx);

int main() {
	int n;
	inp(n);

	string s,t;
	for(int a=1;a<=n;a++) {
		cin>>s;
		cin>>t;
		// compute(s,0);
		memset(lps,0,sizeof lps);
		pre(s,0);
		compute(t,1);
		
		solve1(t,s,0);
		solve(s,t,1);

		memset(A,0,sizeof A);
		solve();

		printf("Case %d: %d\n", a,ans);
	}
	return 0;
}

void pre(string& pat,int idx) {

	int len=0;
	lps[0][idx]=0;
	int i=0,m=pat.length();

	while(i<(m-1)) {
		if(pat[i]==pat[i-len-1]) {
			lps[i][idx]=++len;
			i++;
		}
		else {
			if(len!=0)
				len=lps[len-1][idx];
			else {
				lps[i][idx]=0;
				i++;
			}
		}
	}


}
void solve(string& txt,string& pat,int idx) {
	int m=pat.length();
	int n=txt.length();
	ans=0;

	int j=0,i=0;

	while(i<n) {
		if(pat[j]==txt[i]) {
			if(A[j+1]>(i-j))
				ans=max(ans,i+1);
			j++;
			i++;
		}

		if(j==m)
			j=lps[j-1][idx];
		else if(pat[j]!=txt[i]) {
			if(j!=0) {
				j=lps[j-1][idx];

			}
			else
				i++;
		}
		else
			;
	}
}

// not yet completed ...!!!
void solve1(string& txt,string& pat,int idx) {
	int m=pat.length();
	int n=txt.length();

	int j=0,i=0;

	while(i<n) {
		if(pat[j]==txt[i]) {
			j++;
			i++;
		}

		if(j==m)
			j=lps[j-1][idx];
		else if(pat[j]!=txt[i]) {
			if(j!=0)
				j=lps[j-1][idx];
			else
				i++;
		}
		else
			;
	}
}

void compute(string & pat,int idx) {
	int len=0;
	lps[0][idx]=0;
	int i=1,m=pat.length();

	while(i<m) {
		if(pat[i]==pat[len]) {
			lps[i][idx]=++len;
			i++;
		}
		else {
			if(len!=0)
				len=lps[len-1][idx];
			else {
				lps[i][idx]=0;
				i++;
			}
		}
	}
}

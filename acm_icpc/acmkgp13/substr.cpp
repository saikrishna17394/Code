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

string s,pat;
int dp[1000001],A[10];
int conv(int n) {
	vector<char> v;
	int num=0;
	while(n) {
		v.push_back(n%10);
		n/=10;
		num++;
	}

	for(int i=v.size()-1;i>=0;i--)
		s+='0'+v[i];
	return num;
}

int main() {
	int t,n,ans,val;
	s="1";
	dp[1]=1;
	for(int i=2;i<1000001;i++)
		dp[i]=conv(i)+dp[i-1];
	// for(int i=2;i<21;i++)
	// 	dp[i]=conv(i)+dp[i-1];

	inp(t);
	while(t--) {
		inp(n);
		cin>>pat;

		A[0]=0;
		int len=0,i,j;
		for(i=1;i<pat.length();i++) {

			while(1) {
				if(pat[i]==pat[len]) {
					A[i]=++len;
					break;
				}
				else {
					if(len!=0) 
						len=A[len-1];
					else {
						A[i]=len;
						break;
					}
				}
			}
		}

		ans=0;
		val=pat.length();

		i=0;j=0;
		for(j=0;j<dp[n];j++) {
			// cout<<"Sai\n"<<i<<"\n";
			while(1) {
				// cout<<i<<" "<<j<<" "<<pat[i]<<" "<<ch<<" "<<A[i]<<endl;
				if(pat[i]==s[j]) {
					i++;
					break;
				}
				if(i==0) {
					break;
				}
				i=A[i-1];
			}

			if(i==val) {
				ans++;
				i=A[i-1];
			}
		}

		printf("%d\n", ans);

	}
	return 0;
}
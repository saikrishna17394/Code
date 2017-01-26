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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
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

int t,n,r;
string s;

int A[26],fac[11];

int main() {
	inp(t);

	fac[0]=1;

	for(int i=1;i<11;i++)
		fac[i]=i*fac[i-1];

	while(t--) {
		cin>>s;
		n=s.length();
		r=1;
		memset(A,0,sizeof A);

		for(int i=0;i<n;i++)
			A[s[i]-'a']++;

		for(int i=0;i<n;i++) {
			for(int j=(s[i]-'a'+1);j<26;j++) {
				if(A[j]>0) {
					A[j]--;
					int val=fac[n-i-1];

					for(int k=0;k<26;k++)
						val/=fac[A[k]];
					r+=val;
					A[j]++;
				}
			}
			A[s[i]-'a']--;
		}

		vector<char> v;

		while(r>0) {
			int num=r%26;
			if(num==0)
				num+=26;
			v.push_back('A'+num-1);
			r-=num;
			r/=26;
		}

		for(int i=v.size()-1;i>=0;i--)
			printf("%c",v[i] );
		printf("\n");
	}

	return 0;
}
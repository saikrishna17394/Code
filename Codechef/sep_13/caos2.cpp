#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int te,n,m,ans,a,num,primes[251]={0};

	int l[500][500],r[500][500],t[500][500],b[500][500];

	primes[2]=1;

	for(int i=3;i<251;i++) {
		int k=sqrt(i),j;
		for(j=2;j<=k;j++) {
			if(i%j==0)
				break;
		}
		if(j>k)
			primes[i]=primes[i-1]+1;
		else
			primes[i]=primes[i-1];
	}

	string s[500];
	inp(te);
	while(te--) {
		inp(n);
		inp(m);

		for(int i=0;i<n;i++)
			getline(cin,s[i]);

		for(int j=0;j<m;j++) {
			if(n>1) {
				if(s[0][j]=='^')
					t[1][j]=1;
				else
					t[1][j]=0;
			}

			for(int i=2;i<n;i++) {
				if(s[i-1][j]=='^')
					t[i][j]=t[i-1][j]+1;
				else
					t[i][j]=0;
			}
		}

		for(int j=0;j<m;j++) {
			if(n>1) {
				if(s[n-1][j]=='^')
					b[n-2][j]=1;
				else
					b[n-2][j]=0;
			}

			for(int i=n-3;i>=0;i--) {
				if(s[i+1][j]=='^')
					b[i][j]=b[i+1][j]+1;
				else
					b[i][j]=0;
			}
		}

		for(int i=0;i<n;i++) {
			if(m>1) {
				if(s[i][0]=='^')
					l[i][1]=1;
				else
					l[i][1]=0;
			}

			for(int j=2;j<m;j++) {
				if(s[i][j-1]=='^')
					l[i][j]=l[i][j-1]+1;
				else
					l[i][j]=0;
			}
		}

		for(int i=0;i<n;i++) {
			if(m>1) {
				if(s[i][m-1]=='^')
					r[i][m-2]=1;
				else
					r[i][m-2]=0;
			}

			for(int j=m-3;j>=0;j--) {
				if(s[i][j+1]=='^')
					r[i][j]=r[i][j+1]+1;
				else
					r[i][j]=0;
			}
		}


		ans=0;

		for(int i=2;i<n-2;i++) {
			for(int j=2;j<m-2;j++) {
				if(s[i][j]=='^') {
					num=min(l[i][j],r[i][j]);
					num=min(num,t[i][j]);
					num=min(num,b[i][j]);
					// cout<<i+1<<" "<<j+1<<" "<<num<<" "<<" "<<primes[num]<<endl;
					ans+=primes[num];
				}
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
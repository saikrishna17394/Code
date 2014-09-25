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
	int t,n,m,ans,a,num;
	string s[50];
	inp(t);
	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<n;i++)
			getline(cin,s[i]);
		ans=0;

		for(int i=2;i<n-2;i++) {
			for(int j=2;j<m-2;j++) {
				if(s[i][j]=='^') {
					num=inf;
					a=0;

					int k=j+1;
					while(k<m && s[i][k]=='^') {
						a++;
						k++;
					}
					num=min(num,a);

					k=j-1;
					a=0;
					while(k>=0 && s[i][k]=='^')
						a++,k--;

					k=i+1;
					num=min(num,a);
					a=0;

					while(k<n && s[k][j]=='^')
						a++,k++;
					num=min(num,a);

					k=i-1;
					a=0;
					while(k>=0 && s[k][j]=='^')
						a++,k--;

					num=min(num,a);
					if(num>1)
						ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
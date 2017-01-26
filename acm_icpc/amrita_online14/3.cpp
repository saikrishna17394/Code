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

#define mod 1000000009
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

string s;
int q,m,l,len;

int A[2][600];

int main() {
	cin>>s;	

	inp(q);
	len=s.length();

	while(q--) {
		memset(A,0,sizeof A);
		inp(m);
		inp(l);
		A[0][(s[0]-'0')%m]=1;

		// cout<<"0 : \n";
		// for(int j=0;j<m;j++)
		// 	cout<<A[0][j]<<" ";
		// printf("\n");
		int ans=0;
		ans+=A[0][l];

		for(int i=1;i<len;i++) {
			int num=s[i]-'0';
			for(int j=0;j<m;j++)
				A[i%2][j]=0;

			for(int j=0;j<m;j++) {
				int val=j*10+num;
				val%=m;
				A[i%2][val]+=A[(i-1)%2][j];
			}
			A[i%2][num%m]++;
			// cout<<i<<" "<<" : \n";
			// for(int j=0;j<m;j++)
			// 	cout<<A[i%2][j]<<" ";
			// cout<<endl;
			ans+=A[i%2][l];
		}

		printf("%d\n", ans);
	}
	return 0;
}
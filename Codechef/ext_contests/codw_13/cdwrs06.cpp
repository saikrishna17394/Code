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

int main() {
	int k,n,A[100001],q,m,num,money;
	string s;
	int lazy[1000],ans;
	inp(n);
	k=sqrt(n);

	inp(q);

	while(q--) {
		cin>>s;

		if(s[0]=='U') {
			inp(num);
			inp(money);
			if(num<=k)
				lazy[num]+=money;
			else {
				for(int i=num;i<=n;i+=num)
					A[i]+=money;
			}
		}
		else {
			inp(num);
			ans=A[num];

			for(int i=1;i<=k;i++) {
				if(num%i==0)
					ans+=lazy[i];
			}

			printf("%d\n", ans);
		}
	}
	return 0;
}
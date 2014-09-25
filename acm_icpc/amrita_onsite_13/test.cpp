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
#define lim 100010
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
	int ans=0;
	int A[]={1,2,3,4,5,6,7,8,9,10};
	map<vector<int>,int> m;
	int val=10;
	for(int j=1;j<=10;j++) {
		ans=0;
		sort(A,A+10);
		m.clear();
		do {
			bool ok=true;
			int num=0;
			vector<int> v;
			for(int i=0;i<j;i++) {
				if(A[i]==i+1)
					ok=false;
				v.push_back(A[i]);
			}
			// cout<<"dude\n";
			if(ok && m.find(v)==m.end()) {
				m[v]=1;
				// for(int i=0;i<j;i++)
				// 	cout<<A[i]<<" ";
				// cout<<endl;
				// cout<<A[0]<<endl;
				ans++;
			}

		}while(next_permutation(A,A+10));

		cout<<"10 "<<j<<" "<<((lli)ans*(lli)val)%mod<<endl;
		val*=(10-j);
	}
	return 0;
}
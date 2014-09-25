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
	int t,n;
	inp(t);
	string s1;

	while(t--) {
		inp(n);
		bool ok=false;
		cin>>s1;
		int A[10];
		stack<int> st;
		for(int i=1;i<=n;i++)
			A[i]=1;

		for(int i=0;i<n;i++) {
			int val=s1[i]-'0';

			if(A[val]) {
				for(int j=1;j<val;j++) {
					if(A[j]) {
						A[j]=0;
						st.push(j);
					}
				}
				A[val]=0;
			}
			else if(!st.empty() && st.top()==val) {
				st.pop();
			}
			else {
				ok=true;
				// cout<<i<<endl;
				printf("No\n");
				break;
			}
		}
		if(ok)
			continue;
		printf("Yes\n");
	}

	return 0;
}
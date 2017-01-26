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

int t,n;

int main() {
	inp(t);

	while(t--) {
		inp(n);

		int ans=0;

		vector<int> v;

		for(int i=1;i<n;i++) {
			int val=i;
			set<int> s;
			for(int j=1;j<n;j++) {
				s.insert(val);
				val=(val*i)%n;
			}

			if((*s.begin())==0)
				continue;
			if(s.size()!=(n-1))
				continue;
			v.push_back(i);
		}

		if(v.size()==0) {
			printf("0\n");
		}
		else {
			for(int i=0;i<v.size();i++) {
				if(i>0)
					printf(" ");
				printf("%d", v[i]);
			}
			printf("\n");
		}
	}


	return 0;
}
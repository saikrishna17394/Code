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

int n;
vector<vector<int> > v;
vector<string> m;

vector<vector<int> > ans;

int main() {
	inp(n);

	v.resize(n);
	m.resize(n);

	for(int i=0;i<n;i++) {
		m[i]="";
		char ch=getchar();
		while(ch!=',') {
			m[i]+=ch;
			ch=getchar();
		}
		v[i].resize(3);
		for(int j=0;j<3;j++)
			inp(v[i][j]);
	}

	for(int i=0;i<n;i++) {
		cout<<i<<" "<<m[i]<<endl;
		for(int j=0;j<3;j++)
			cout<<v[i][j]<<" ";
		printf("\n");
	}

	return 0;
}
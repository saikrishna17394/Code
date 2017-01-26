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

map<char,int> m;

char A[12]={'C','c','D','d','E','F','f','G','g','A','B','S'};

int main() {

	for(int i=0;i<12;i++)
		m[A[i]]=i;

	int t;

	inp(t);
	char a,b,c;
	while(t--) {
		cin>>a>>b>>c;

		int d=abs(m[a]-m[b]);

		d=min(d,12-d);

		if(d==4)
			printf("Major\n");
		else
			printf("Minor\n");


	}
	return 0;
}
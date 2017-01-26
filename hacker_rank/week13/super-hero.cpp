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
#define lim 100001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int t,n,m;
int p[100][500000];
int b[100][500000];

int main() {
	cin>>t;

	while(t--) {
		cin>>n>>m;

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>p[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>b[i][j];

		int l=1,r=100000;
		
		while(l<r) {
			int m=(l+r)/2;
			
		} 
	}


	return 0;
}
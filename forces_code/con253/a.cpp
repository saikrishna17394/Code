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
#define lim 10000000

using namespace std;

int g[5][5],n,A[5],B[5],A1[5],B1[5];
map<int,int> m;

int main() {
	m['R']=0;
	m['G']=1;
	m['B']=2;
	m['Y']=3;
	m['W']=4;

	memset(g,0,sizeof g);
	memset(A1,0,sizeof A1);
	memset(B1,0,sizeof B1);

	cin>>n;
	char ch,ch1;
	for(int i=0;i<n;i++) {
		ch=getchar();
		while(1) {
			if(ch>='A' && ch<='Z')
				break;
			ch=getchar();
		}
		ch1=getchar();

		g[m[ch]][ch1-'1']=1;
		A1[m[ch]]=1;
		B1[ch1-'1']=1;
	}

	int r=0,c=0;

	for(int i=0;i<5;i++)
		r+=A1[i];

	for(int j=0;j<5;j++)
		c+=B1[j];

	int ans=10;


	// cout<<ans<<endl;

	for(int i=0;i<(1<<5);i++) {
		int mask=i,val=0;
		for(int k=0;k<5;k++) {
			A[k]=mask&1;
			A[k]&=A1[k];
			val+=A[k];
			mask/=2;
		}
		for(int j=0;j<(1<<5);j++) {
			int mask1=j,val1=0;

			for(int k=0;k<5;k++) {
				B[k]=mask1&1;
				B[k]&=B1[k];
				val1+=B[k];
				mask1/=2;
			}

			bool ok=true;
			for(int i1=0;i1<5;i1++) {
				for(int j1=0;j1<5;j1++) {
					if(g[i1][j1]) {
						if((A[i1]==1 || val==r-1) && (B[j1]==1 || val1==c-1))
							;
						else
							ok=false;
					}
					if(!ok)
						break;
				}
				if(!ok)
					break;
			}
			if(ok)
				ans=min(ans,val+val1);
		}
	}

	cout<<ans<<endl;
	return 0;
}
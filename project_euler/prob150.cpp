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
 
using namespace std;

lli A[1000][1000];
map<ii,lli> m,m1;
int main() {
	lli num=0,con=1<<20,ans,val;

	for(int i=0;i<1000;i++) {
		for(int j=0;j<=i;j++) {
			num=(lli)(615949)*num;
			num+=(lli)797807;
			num%=con;
			A[i][j]=num-(con/2);
		}
	}
	ans=A[0][0];
	m[ii(0,0)]=ans;
	val=0;
	for(int i=1;i<1000;i++) {
		// cout<<i<<endl;
		for(int j=0;j<=i;j++) {
			// m1[ii(j,j)]=A[i][j];
			// val=A[i][j];
			for(int k=j+1;k<=i;k++) {
				// cout<<i<<" "<<j<<" "<<k<<endl;
				// val+=A[i][k];
				// ans=min(ans,val+m[ii(j,k-1)]);
				// m1[ii(j,k)]=val+m[ii(j,k-1)];
				val++;
			}
		}
		// m=m1;
		// m1.clear();
	}
	cout<<ans<<endl;
	cout<<val<<endl;
	return 0;
}
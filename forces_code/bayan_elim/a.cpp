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

int t,n;
string s;
// R,P,S
int A[]={2,0,1};
int B[3];
int main() {
	cin>>t;

	map<char,int> m;
	m['R']=0;
	m['P']=1;
	m['S']=2;
	for(int a=1;a<=t;a++) {
		cin>>n;
		cin>>s;
		memset(B,0,sizeof B);

		for(int i=0;i<n;i++) {
			// cout<<m[s[i]]<<" "<<s[i]<<endl;
			B[m[s[i]]]++;
		}

		int val=0;
		for(int i=0;i<3;i++) {
			cout<<i<<" "<<B[i]<<endl;
			if(B[i]>0)
				val=max(val,B[A[i]]);
		}

		// cout<<val<<endl;
		int ans=0;
		for(int i=0;i<3;i++) {
			if(B[A[i]]==val)
				ans+=B[i];
		}
		
		printf("Case #%d:\n", a);
		printf("%d\n", ans);
	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999
#define lim 1000010
using namespace std;

int A[lim][26],idx;
string s;

int main() {
	freopen("autocomplete.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n;


	cin>>t;

	for(int a=1;a<=t;a++) {

		for(int i=0;i<26;i++)
			A[0][i]=-1;
		idx=1;

		lli ans=0;
		printf("Case #%d: ",a);
		cin>>n;		
		for(int i=0;i<n;i++) {
			cin>>s;

			int cur=0;
			bool ok=true;
			// cout<<s<<endl;

			for(int i=0;i<s.length();i++) {
				if(A[cur][s[i]-'a']==-1) {
					if(ok) {
						ans+=(lli)(i+1);
						ok=false;
					}
					A[cur][s[i]-'a']=idx++;
					for(int j=0;j<26;j++)
						A[idx-1][j]=-1;
				}
				cur=A[cur][s[i]-'a'];
			}
			if(ok)
				ans+=(lli)(s.length());
		}
		
		printf("%lld\n", ans);
	}


	return 0;
}
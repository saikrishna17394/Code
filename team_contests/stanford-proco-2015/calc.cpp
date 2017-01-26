#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;


int n;
string s[lim];
int A[lim];

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>s[i];
		if(s[i][0]=='z')
			cin>>A[i];
	}

	int ans=0;

	for(int i=n-1;i>=0;i--) {
		if(s[i][0]=='+')
			ans++;
		else if(s[i][0]=='-')
			ans--;
		else {
			i-=A[i];
		}
	}

	printf("%d\n", ans);

	return 0;
}
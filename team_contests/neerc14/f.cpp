#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int m,f,A[100];
int n;
int q;

int ans[1000]={0};

int B[1000][1000]={0};


int main(){ 
	freopen("filter.in", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("filter.out", "w", stdout);
	cin>>m>>f;

	for(int i=0;i<f;i++) {
		cin>>A[i];
		A[i]%=m;
	}

	cin>>n;

	for(int i=0;i<n;i++) {
		string s;
		cin>>s;

		int idx=0;		
		for(int j=0;j<s.length();j++) {
			int val;
			if(s[j]>='0' && s[j]<='9')
				val=s[j]-'0';
			else
				val=s[j]-'a'+10;

			for(int k=0;k<4;k++,idx++) {
				B[i][idx]=val%2;
				val/=2;
			}
		}
	}

	cin>>q;

	while(q--) {
		int u;
		cin>>u;
		u%=m;

		
		for(int i=0;i<n;i++) {
			bool ok=true;
			for(int j=0;j<f;j++) {
				if(B[i][(u*A[j])%m]==0) {
					ok=false;
					break;
				}
			}
			if(ok)
				ans[i]=1;
		}
 	}

 	int ans1=0;
 	for(int i=0;i<n;i++) {
 		ans1+=ans[i];
 	}

 	cout<<ans1;

 	for(int i=0;i<n;i++) {
 		if(ans[i]>0)
 			cout<<" "<<i;
 	}

 	cout<<endl;

	return 0;
}
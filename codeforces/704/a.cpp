#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 300010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,Q,q,x,t;
int A[lim]={0},cnt[lim]={0};

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n>>Q;


	int tim = -1;

	vector<int> v;

	int ans = 0,count=0;

	for(int i=1;i<=n;i++)
		cnt[i]=-1;

	for(int i=1;i<=Q;i++) {
		scanf("%d %d",&q,&x);

		if(q==1) {
			A[x]++;
			v.push_back(x);
			ans++;
			count++;
		}
		else if(q==2) {
			ans-=A[x];
			A[x]=0;
			cnt[x]=count-1;
		}
		else {
			t=x-1;
			if(t>tim) {
				for(int j=tim+1;j<=t;j++) {
					if(cnt[v[j]]<j) {
						A[v[j]]--;
						ans--;
						cnt[v[j]]=j;
					}
				}
				tim=t;
			}

		}
		printf("%d\n", ans);
	}

	return 0;
}
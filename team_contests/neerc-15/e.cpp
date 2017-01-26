#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;


int n,k;
vector<int> A[10];
int cur_idx[10]={0};

int main(){ 
	freopen("easy.in", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("easy.out", "w", stdout);

	cin>>n>>k;

	for(int i=0;i<n;i++) {
		int num;
		cin>>num;

		for(int j=0;j<num;j++) {
			int val;
			cin>>val;
			A[i].push_back(val);
		}

	}


	int cur=0;

	int num=0;
	int ans=0;
	
	int val=0;

	while(num<k) {

		if(val>=n)
			break;
		if(cur_idx[cur]>=A[cur].size()) {

			if(ans<=50) {
				ans+=50;
				num++;
				val=0;
			}
			else {
				val++;
			}
			cur++;
			cur%=n;
			continue;
		}


		val=0;
		if(A[cur][cur_idx[cur]]>=ans) {
			num++;
			// cout<<cur<<" "<<A[cur][cur_idx[cur]]<<endl;
			ans+=A[cur][cur_idx[cur]];
		}

		cur_idx[cur]++;

		cur++;
		cur%=n;

	}

	ans+=(k-num)*50;
	cout<<ans<<endl;
	return 0;
}
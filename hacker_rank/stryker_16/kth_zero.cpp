#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,m;
int A[lim],tree[lim]={0};

void upd(int idx,int val) {
	while(idx<=n) {
		tree[idx] += val;
		idx += idx&-idx;
	}
}

int solve(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main(){ 
	cin>>n;
	cin>>m;

	for(int i = 1; i<=n; i++) {
		scanf("%d",&A[i]);
		if(A[i] == 0) {
			upd(i, 1);
		}
	}

	while(m--) {
		int q,x,p,k;
		cin>>q;

		if(q == 1) {
			cin>>k;
			
			int val = solve(n);
			
			if(k > val) {
				printf("NO\n");
				continue;
			}
			int l = 1, r = n;


			while(l < r) {
				int m = (l+r)/2;

				val = solve(m);
				if(k <= val)
					r = m;
				else
					l = m+1;

			}
			printf("%d\n", l-1);
		}
		else {
			cin>>p>>x;
			p++;
			if(A[p] != x) {
				if(x == 0)
					upd(p,1);
				else if(A[p] == 0)
					upd(p,-1);
				A[p] = x;
			}
		}

	}

	return 0;
}
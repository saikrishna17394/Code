#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,int> di;

int n,A[lim],q,k;
ii B[lim];
int ans[lim];
pair<ii,int> C[lim];

int val = 1;
int l = 1, r = 1;
int pre[lim] = {0};

void push(int num) {
	if(pre[num-1] == 1) {
		if(pre[num+1] == 1)
			val--;
	}
	else {
		if(pre[num+1] == 0)
			val++;
	}
	pre[num] = 1;
}

void remove(int num) {
	if(pre[num-1] == 1) {
		if(pre[num+1] == 1)
			val++;
	}
	else {
		if(pre[num+1] == 0)
			val--;
	}
	pre[num] = 0;
}

int main() {
	cin >> n >> q;

	for(int i = 1 ; i <= n; i++) 
		cin >> A[i];

	k = sqrt(n);

	// cout<< n<< k<<endl;
	for(int i = 0; i < q; i++) {
		cin >> B[i].first >> B[i].second;
		C[i].second = i;
		C[i].first.first = B[i].first/k;
		C[i].first.second = B[i].second;
	}

	sort(C,C+q);


	pre[A[1]] = 1;

	for(int j = 0; j < q; j++) {
		int idx = C[j].second;
		int cur_l = B[idx].first;
		int cur_r = B[idx].second;

		if(cur_l > r) {
			for(int i = l; i <= r; i++)
				pre[A[i]] = 0;
			val = 0;

			for(int i = cur_l; i <= cur_r; i++)
				push(A[i]);
		}
		else if(cur_l >= l) {
			for(int i = l; i < cur_l; i++)
				remove(A[i]);
			for(int i = r+1; i<= cur_r;i++)
				push(A[i]);
			for(int i = cur_r+1; i <= r;i++)
				remove(A[i]);
		}
		else {
			for(int i = cur_l; i <= min(cur_r,l-1);i++)
				push(A[i]);
			for(int i = cur_r+1; i <= r; i++)
				remove(A[i]);
			for(int i = r+1; i<= cur_r;i++)
				push(A[i]);
		}
		l =cur_l;
		r = cur_r;
		ans[idx] = val;
	}

	for(int i =0; i< q;i++)
		printf("%d\n", ans[i]);

	return 0;
}
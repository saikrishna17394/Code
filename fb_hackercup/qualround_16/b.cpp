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

using namespace std;

int main() {
	freopen("lazy_loading.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n,w[100];
	cin>>t;

	for(int a=1;a<=t;a++) {
		cin >> n;

		for(int i = 0; i < n; i++)
			cin >> w[i];

		sort(w, w + n);

		int ans = 0;

		int l = 0, r = n - 1;

		while(l <= r) {
			int weight = w[r];
			int max_wt = w[r];

			r--;
			while(weight < 50 ) {
				if(l <= r) {
					l++;
					weight += max_wt;
				}
				else
					break;
			}
			// cout<< l <<" "<< r<<" "<<weight<<endl; 
			if(weight >= 50)
				ans++;
		}

		printf("Case #%d: %d\n",a, ans);

	}


	return 0;
}
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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16

using namespace std;

vector<int> v[4];
int n,num,t;

int main() {

	cin>>n>>t;

	for(int i=0;i<n;i++) {
		cin>>num;
		v[num].push_back(i);
	}

	int i,j;
	while(t--) {
		cin>>i>>j;

		for(int a=1;a<=3;a++) {
			vector<int>::iterator it=lower_bound(v[a].begin(),v[a].end(),i);
			if(it!=v[a].end() && (*it)<=j) {
				// cout<<*it<<endl;
				printf("%d\n", a);
				break;
			}
		}
	}

	return 0;
}
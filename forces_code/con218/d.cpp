#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
#define lim 200010
typedef long long int lli;
typedef pair<int,int> ii;

int n,A[lim],B[lim]={0},par[lim];

int root(int idx) {
	if(idx==n)
		return n;
	if(A[idx]!=B[idx])
		return idx;
	par[idx]=root(par[idx]);
	return par[idx];
}

int main() {

	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i];
		par[i]=i+1;
	}

	int m,a,b,c,idx;
	cin>>m;

	while(m--) {
		// cout<<"dude\n";
		cin>>a;
		if(a==1) {
			cin>>b;
			b--;
			cin>>c;
			idx=b;

			while(c) {
				// cout<<idx<<" "<<c<<" "<<n<<endl;
				if(idx==n)
					break;
				if(B[idx]+c<=A[idx]) {
					B[idx]+=c;
					c=0;
				}
				else {
					c-=A[idx]-B[idx];
					B[idx]=A[idx];
					idx=root(idx);
				}
			}
		}
		else {
			cin>>b;
			b--;
			cout<<B[b]<<endl;
		}
		// cout<<"man\n";
	}
	return 0;
}
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
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

map<int,lli> m;
int n,q,x,A[100000],cnt;

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

pair<int,ii> B[100];

int main() {
	cin>>n;

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	m[A[0]]++;
	cnt=0;
	B[cnt++]=make_pair(A[0],ii(0,0));

	for(int i=1;i<n;i++) {
		int idx=0;

		B[cnt++]=make_pair(A[i],ii(i,i));
		for(int j=0;j<cnt;j++) {
			int g=gcd(A[i],B[j].first);

			if(j>0 && g==B[idx-1].first)
				B[idx-1].second.second=B[j].second.second;
			else {
				B[idx].first=g;
				B[idx++].second=B[j].second;
			}
		}
		cnt=idx;

		for(int j=0;j<cnt;j++) {
			ii p=B[j].second;
			m[B[j].first]+=(lli)(p.second-p.first+1);
		}
	}

	cin>>q;
	while(q--) {
		scanf("%d",&x);
		cout<<m[x]<<endl;
	}

	return 0;
}
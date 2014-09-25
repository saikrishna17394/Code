#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

vector<int> v[100001];

int diff(int i) {
	int sz=v[i].size();

	if(sz==0)
		return -1;
	if(sz==1)
		return 0;

	int ans=v[i][1]-v[i][0];

	for(int j=2;j<sz;j++) {
		if((v[i][j]-v[i][j-1])!=ans)
			return -1;
	} 
	return ans;
}

int main() {
	int n,num,ans,cnt=0;

	scanf("%d",&n);

	for(int i=0;i<n;i++) {
		scanf("%d",&num);
		v[num].push_back(i);
	}

	for(int i=1;i<=100000;i++) {
		ans=diff(i);
		if(ans>=0) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for(int i=1;i<=100000;i++) {
		ans=diff(i);
		if(ans>=0) {
			printf("%d %d\n",i,ans);
		}
	}

	return 0;
}
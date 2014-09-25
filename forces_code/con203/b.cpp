#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,type[100001],par[100001],ans=0;
	int mark[100001]={0},cnt[100001]={0},pos;

	scanf("%d",&n);
	mark[0]=-1;
	for(int i=1;i<=n;i++)
		scanf("%d",&type[i]);

	for(int i=1;i<=n;i++) {
		scanf("%d",&par[i]);
		if(par[i]) {
			if(cnt[par[i]]) {
				mark[par[i]]=-1;
			}
			else
				cnt[par[i]]++;
		}
	}

	pos=-1;
	ans=0;
	int val,num;
	for(int i=1;i<=n;i++) {
		if(type[i]==1) {
			val=1;
			num=i;
			while(mark[par[num]]==0) {
				val++;
				num=par[num];
			}
			if(val>ans) {
				ans=val;
				pos=i;
			}
		}

	}

	printf("%d\n", ans);
	vector<int> v;

	v.push_back(pos);

	while(mark[par[pos]]==0) {
		v.push_back(par[pos]);
		pos=par[pos];
	}

	for(int i=v.size()-1;i>=0;i--)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}
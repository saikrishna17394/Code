#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 99999999
typedef long long int lli;

int n,m,A[100000],ans[100000],pre[100001]={0},num;

int main() {
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	ans[n-1]=1;
	pre[A[n-1]]=1;

	for(int i=n-2;i>=0;i--) {
		ans[i]=ans[i+1];
		if(!pre[A[i]]) {
			pre[A[i]]=1;
			ans[i]++;
		}
	}

	while(m--) {
		scanf("%d",&num);
		printf("%d\n", ans[num-1]);
	}
	return 0;
}
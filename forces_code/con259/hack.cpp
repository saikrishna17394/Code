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

int a[100000];

int main() {
	int n,k,s,i;
	memset(a,0,sizeof a);

	cin>>n;

	for(i=0;i<n;i++)
		cin>>a[i];

	s=a[0];
	k=-1;

	for(i=1;i<n;i++) {
		if(a[i]<s) {
			if(k==-1)
				k=i-1;
			else {
				printf("-1\n");
				break;
			}
		}
		s=a[i];
	}

	if(i<n)
		return 0;
	if(k==-1)
		printf("0\n");
	else if(a[n-1]>a[0])
		printf("-1\n");
	else
		printf("%d\n", n-k-1);
	return 0;
}
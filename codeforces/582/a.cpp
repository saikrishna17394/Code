#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


// int A[500*500];
map<int,int> m;

int main(){ 
	// cin.sync_with_stdio(false);
	int n;

	cin>>n;

	for(int i=0;i<n*n;i++) {
		int num;
		scanf("%d",&num);
		m[num]++;
	}

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		if((it->second)%2==1)
			printf("%d ",it->first );
	}

	printf("\n");

	return 0;
}
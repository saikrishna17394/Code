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

int main() {
	int n,x,sum=0,num,ans;
	
	cin>>n>>x;

	for(int i=0;i<n;i++) {
		cin>>num;
		sum+=num;
	}

	if(sum<0)
		sum*=-1;

	ans=sum/x;

	if(sum%x!=0)
		ans++;
	cout<<ans<<endl;

	return 0;
}
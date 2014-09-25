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

int n,A[100000];
map<int,int> m;

int main() {
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i];
		m[A[i]]=1;
	}

	int cnt=0;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
		it->second=cnt++;

	int ans=0;

	for(int i=0;i<n;i++) {
		if(m[A[i]]==0) {
			ans=n-i;
			if(ans==n)
				ans=0;

			bool ok=true;

			int val=0;
			
			for(int j=1;j<n;j++) {
				if(m[A[(i+j)%n]]==val)
					;
				else if(m[A[(i+j)%n]]==val+1)
					val++;
				else
					ok=false;
			}
			if(!ok) {
				printf("-1\n");
				return 0;
			}
			break;
		}
	}

	printf("%d\n",ans);
	return 0;
}
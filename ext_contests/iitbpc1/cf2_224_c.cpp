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
set<int> ans;

bool ap() {
	int dif=A[1]-A[0];

	for(int i=2;i<n;i++) {
		if((A[i]-A[i-1])!=dif)
			return false;
	}
	return true;
}


int main() {
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A,A+n);

	if(n==1) {
		printf("-1\n");
		return 0;
	}

	if(n==2) {
		if((A[1]-A[0])%2==0)
			ans.insert((A[0]+A[1])/2);
	}
	if(ap()) {
		ans.insert(A[0]-A[1]+A[0]);
		ans.insert(A[n-1]+A[1]-A[0]);
	}

	int dif=A[1]-A[0],cnt=0,val,idx;
	

	for(int i=2;i<n;i++) {
		if((A[i]-A[i-1])!=dif) {
			cnt++;
			val=A[i]-A[i-1];
			idx=i;
		}
	}
	
	if(cnt==1 && val==2*dif) {
		ans.insert((A[idx]+A[idx-1])/2);
	}


	dif=A[1]-A[0],cnt=0,val,idx;
	
	if(dif%2==0) {
		for(int i=2;i<n;i++) {
			if((A[i]-A[i-1])!=dif/2) {
				cnt++;
				// val=A[i]-A[i-1];
				// idx=i;
			}
		}
		
		if(cnt==0) {
			ans.insert((A[0]+A[1])/2);
		}
	}

	cout<<ans.size()<<endl;

	for(set<int>::iterator it=ans.begin();it!=ans.end();it++) {
		printf("%d ", *it);
	}
	printf("\n");
	return 0;
}
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


int n,A[100010];
map<int,int> m;

int main() {
	scanf("%d",&n);

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		m[A[i]]=1;
	}

	int cnt=0;

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		it->second=cnt++;
	}

	
	for(int i=0;i<n;i++)
		A[i]=m[A[i]];


	int idx=0;

	bool ok=true;
	for(int i=0;i<n;i++) {
		// cout<<i<<" "<<A[i]<<endl;
		if(A[i]!=i) {
			idx=i;
			ok=false;
			break;
		}
	}

	if(!ok) {
		ok=true;
		for(int i=A[idx]+1;i<n;i++) {
			if(A[i]!=i) {
				ok=false;
				break;
			}
		}
		if(!ok)
			printf("no\n");
		else {
			int num=A[idx];

			// cout<<idx+1<<" "<<
			for(int i=idx;i<=A[idx];i++) {
				if(A[i]!=num) {
					ok=false;
					break;
				}
				num--;
			}
			if(ok) {
				printf("yes\n");
				printf("%d %d\n",idx+1,A[idx]+1);
			}
			else
				printf("no\n");
		}
	}
	else {
		printf("yes\n");
		printf("1 1\n");
	}


	

	return 0;
}
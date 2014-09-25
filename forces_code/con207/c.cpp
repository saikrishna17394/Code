#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n,m,A[300001]={0},l,r,x;
	scanf("%d %d",&n,&m);
	set<int> s;
	
	for(int i=1;i<=n;i++) {
		s.insert(i);
	}

	while(m--) {
		scanf("%d %d %d",&l,&r,&x);
		set<int>::iterator it=s.lower_bound(l);
		set<int> s1;
		for(;it!=s.end();it++) {
			if((*it)>r)
				break;
			if((*it)!=x) {
				A[*it]=x;
				s1.insert(*it);
			}
		}

		for(set<int>::iterator it1=s1.begin();it1!=s1.end();it1++)
			s.erase(*it1);
	}

	for(int i=1;i<=n;i++)
		printf("%d ",A[i] );
	printf("\n");
	return 0;
}
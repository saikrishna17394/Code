#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n,A[100001]={0},m,a,b,c;

	scanf("%d %d",&n,&m);

	scanf("%d %d %d",&a,&b,&c);
	A[a]=1;
	A[b]=2;
	A[c]=3;

	m--;

	while(m--) {
		scanf("%d %d %d",&a,&b,&c);
		set<int> s;
		s.insert(1);
		s.insert(2);
		s.insert(3);
		if(A[a]) {
			s.erase(A[a]);
			set<int>::iterator it=s.begin();
			A[b]=*it;
			it++;
			A[c]=*it;
			continue;
		}
		if(A[b]) {
			s.erase(A[b]);
			set<int>::iterator it=s.begin();
			A[a]=*it;
			it++;
			A[c]=*it;
			continue;
		}
		if(A[c]) {
			s.erase(A[c]);
			set<int>::iterator it=s.begin();
			A[a]=*it;
			it++;
			A[b]=*it;
			continue;
		}
		A[a]=1;
		A[b]=2;
		A[c]=3;
	}

	for(int i=1;i<=n;i++) {
		if(A[i])
			printf("%d ",A[i]);
		else
			printf("1 ");
	}
	printf("\n");
	return 0;
}
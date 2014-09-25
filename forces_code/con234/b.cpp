#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;


int main() {
	int n,m,A[1000];

	cin>>n>>m;

	set<int> s2;

	string s;

	while(n--) {
		cin>>s;

		int cnt=0;

		for(int i=0;i<m;i++) {
			if(s[i]=='G')
				A[cnt++]=(i+1);
			if(s[i]=='S')
				A[cnt++]=-(i+1);
		}

		bool ok=true;

		set<int> s1;

		for(int i=0;i<(cnt-1);i++) {
			if(A[i]>0) {
				if(A[i+1]>0) {
					ok=false;
					break;
				}
				s1.insert(-A[i+1]-A[i]);
			}
		}

		if(cnt) {
			if(A[cnt-1]>0)
				ok=false;
		}
		if(s1.size()>2)
			ok=false;

		if(!ok) {
			printf("-1\n");
			return 0;
		}

		if(s1.size())
			s2.insert(*s1.begin());
	}

	printf("%d\n", s2.size());
	return 0;
}
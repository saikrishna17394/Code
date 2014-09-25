#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef pair<char,int> ii;

int main() {
	int n,m,num;
	set<int> s;
	cin>>n;

	cin>>m;

	for(int i=0;i<m;i++) {
		cin>>num;
		s.insert(num);
	}

	if(s.find(1)!=s.end() || s.find(n)!=s.end()) {
		printf("NO\n");
		return 0;
	}

	for(set<int>::iterator it=s.begin();it!=s.end();it++) {
		num=*it;
		if(s.find(num+1)!=s.end() && s.find(num+2)!=s.end()) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<char,int> ii;

vector<ii> v;

int main() {
	string s;
	cin>>s;

	v.push_back(ii(s[0],1));

	int ind=0;

	for(int i=1;i<s.length();i++) {
		if(s[i]==v[ind].first)
			v[ind].second++;
		else {
			v.push_back(ii(s[i],1));
			ind++;
		}
	}

	for(int i=0;i<v.size();i++) {
		if(v[i].second>=3)
			v[i].second=2;
	}

	int x=0;

	for(int i=0;i<v.size();i++) {
		if(v[i].second==1) {
			printf("%c",v[i].first);
			x=0;
		}
		else if( (i>0 && v[i-1].second==2) || ((i+1)<v.size() && v[i+1].second==2) ) {
			if(x) {
				printf("%c", v[i].first);
				// v[i].second=1;
			}
			else
				printf("%c%c",v[i].first,v[i].first );
			x^=1;
		}
		else {
			printf("%c%c",v[i].first,v[i].first);
			x=0;
		}
	}
	printf("\n");
	return 0;
}
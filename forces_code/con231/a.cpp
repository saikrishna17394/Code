#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;


int main() {
	string s;
	cin>>s;

	int len=s.length();

	int a=0,b=0,c=0;

	int idx=0;

	while(s[idx++]!='+')
		a++;
	// idx++;

	while(s[idx++]!='=')
		b++;
	// idx++;
	while(idx<len) {
		c++;
		idx++;
	}
	// cout<<a<<" "<<b<<" "<<c<<endl;
	int d=a+b;

	if(d!=c) {
		if(abs(d-c)!=2) {
			printf("Impossible\n");
			return 0;
		}

		if(d<c) {
			a++;
			c--;
		}
		else {
			if(a>1)
				a--;
			else
				b--;
			c++;
		}
	}

	for(int i=0;i<a;i++)
		printf("|");
	printf("+");
	for(int i=0;i<b;i++)
		printf("|");
	printf("=");
	for(int i=0;i<c;i++)
		printf("|");
	printf("\n");
	return 0;
}
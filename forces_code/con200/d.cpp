#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
#define lli long long int

int main() {
	int len,num,cnts=0;
	string s;
	cin>>s;
	len=s.length();

	if(len&1) {
		printf("No\n");
		return 0;
	}
	num=1;
	int i=1;
	cnts=1;


	for(;i<len;i++) {
		if(s[i]==s[i-1])
			num++;
		else {
			if(num==1 && cnts>1) {
				break;
			}
			num=1;
			cnts++;
		}
	}

	// cout<<len<<i<<" "<<

	if(num==1 && i<len)
		printf("No\n");
	else if(cnts&1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
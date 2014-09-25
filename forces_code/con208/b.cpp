#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
string s[100000],text;
int len,n,pos;

bool check(int i) {
	while(pos<len) {
		if(text[pos++]=='<')
			break;
		// pos++;
	}
		if(pos==len)
			return false;

	while(pos<len) {
		if(text[pos++]=='3')
			break;
		// pos++;
	}
		if(pos==len)
			return false;

	int i1,len1=s[i].length();

	for(i1=0;i1<len1;i1++) {
		while(pos<len) {
			if(text[pos]==s[i][i1])
				break;
			pos++;
		}
		if(pos==len)
			return false;
		pos++;
	}
	if(i<(n-1))
		return true;

	while(pos<len) {
		if(text[pos++]=='<')
			break;
		// pos++;
	}
		if(pos==len)
			return false;

	while(pos<len) {
		if(text[pos++]=='3') {
			return true;
		}
		// pos++;
	}

}
int main() {

	scanf("%d",&n);

	for(int i=0;i<n;i++)
		cin>>s[i];

	cin>>text;
	len=text.length();

	int i,ind;
	pos=0;

	for(i=0;i<n;i++) {
		// cout<<pos<<endl;
		if(!check(i)) {
			printf("no\n");
			return 0;
		}
	}

	printf("yes\n");

	return 0;
}
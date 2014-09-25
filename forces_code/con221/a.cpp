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
	int len,idx;
	cin>>s;
	len=s.length();
	lli l=0,r=0,val;
	for(int i=0;i<len;i++)
		if(s[i]=='^')
			idx=i;

	for(int i=0;i<idx;i++)
		if(s[i]!='=') {
			val=(s[i]-'0');
			val*=(lli)(idx-i);
			l+=val;
		}
	for(int i=idx+1;i<len;i++)
		if(s[i]!='=') {
			val=(s[i]-'0');
			val*=(lli)(i-idx);
			r+=val;
		}
	if(l==r)
		printf("balance\n");
	else if(l>r)
		printf("left\n");
	else
		printf("right\n");
	return 0;
}
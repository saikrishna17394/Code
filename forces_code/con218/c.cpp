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
	lli A[3]={0},n[3],c[3],r,ans,B[3];

	cin>>s;

	for(int i=0;i<s.length();i++) {
		if(s[i]=='B')
			A[0]++;
		else if(s[i]=='S')
			A[1]++;
		else
			A[2]++;
	}

	for(int i=0;i<3;i++)
		cin>>n[i];

	for(int i=0;i<3;i++) {
		cin>>c[i];
		c[i]*=A[i];
	}
	cin>>r;

	for(int i=0;i<3;i++)
		B[i]=n[i]/A[i];

	return 0;
}
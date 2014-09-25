#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int main() {
	string s;
	cin>>s;
	int num,n;

	n=s.length();

	if(s.length()==1)
		num=s[0]-'0';
	else {
		num=(s[n-2]-'0')*10;
		num+=s[n-1]-'0';
	}
	num%=4;

	int rem=0;

	for(int i=1;i<5;i++) {
		int val=1;
		for(int j=0;j<num;j++)
			val=(val*i)%5;
		rem=(rem+val)%5;
	}
	printf("%d\n", rem);
	return 0;
}
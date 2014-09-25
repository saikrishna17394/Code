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
	int n=s.length();

	lli odd=0,even=0,idx1=0,idx2=0;

	for(int i=0;i<n;i++) {
		if(s[i]=='a') {
			odd+=idx1;
			even+=idx2;
			idx1++;
			odd++;
		}
		swap(idx1,idx2);
	}

	idx1=0;idx2=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='b') {
			odd+=idx1;
			even+=idx2;
			idx1++;
			odd++;
		}
		swap(idx1,idx2);
	}

	printf("%lld %lld\n", even,odd);
	return 0;
}
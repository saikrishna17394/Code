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

const double pi = 2 * acos(0.0);

int n,p;
string s;

int solve(int i) {
	if(i==0) {
		if((s[i]-'a'+1)<p) {
			s[i]++;
			return 1;
		}
		return -1;
	}
	if(i==1) {
		int num=s[1]-'a'+1;
		int num1=s[0]-'a'+1;

		for(int a=num+1;a<=p;a++) {
			if(num1!=a) {
				s[i]='a'+a-1;
				return 1;
			}
		}

		if(solve(i-1)==-1)
			return -1;
		for(int a=0;a<p;a++) {
			if(s[0]!=('a'+a)) {
				s[1]='a'+a;
				return 1;
			}
		}
		return -1;
	}
	int num=s[i]-'a'+1;
	int num1=s[i-1]-'a'+1;
	int num2=s[i-2]-'a'+1;

	for(int a=num+1;a<=p;a++) {
		if(num1!=a && num2!=a) {
			s[i]='a'+a-1;
			return 1;
		}
	}

	if(solve(i-1)==-1)
		return -1;
	for(int a=0;a<p;a++) {
		if(s[i-1]!=('a'+a) && s[i-2]!=('a'+a)) {
			s[i]='a'+a;
			return 1;
		}
	}
	return -1;

}

int main() {
	cin>>n>>p>>s;

	if(solve(n-1)==-1)
		printf("NO\n");
	else
		cout<<s<<endl;

	return 0;
}
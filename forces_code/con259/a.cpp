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

int n;
string s[101];

int main() {
	cin>>n;

	for(int i=0;i<=n/2;i++) {
		string s1;

		for(int j=0;j<n;j++) {
			if(abs(n/2-j)<=i)
				s1+="D";
			else
				s1+="*";
		}
		s[i]=s1;
		s[n-i-1]=s1;
	}

	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;

	return 0;
}
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
	int n;
	string s[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

	// for(int i=0;i<8;i++)
	// 	cout<<s[i]<<endl;

	cin>>n;

	string a;
	cin>>a;

	for(int i=0;i<8;i++) {
		if(a.length()==s[i].length()) {
			bool ok=true;
			for(int j=0;j<a.length();j++) {
				if(a[j]==s[i][j] || a[j]=='.')
					;
				else
					ok=false;
			}
			if(ok)
				cout<<s[i]<<endl;
		}
	}



	return 0;
}
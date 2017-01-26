#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999

using namespace std;

int conv(string s) {
	int ret=0;
	for(int i=0;i<s.length();i++) {
		ret*=10;
		ret+=(s[i]-'0');
	}
	return ret;
}

int main() {
	freopen("cooking_the_books.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n;
	cin>>t;
	string s;

	for(int a=1;a<=t;a++) {
		cin>>s;

		printf("Case #%d: ",a);
		// cout<<s<<endl;

		n=s.length();

		string s1;

		// bool ok=false;

		set<int> m;
		m.insert(conv(s));

		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				s1=s;
				if(i==0 && s[j]=='0')
					continue;
				swap(s1[i],s1[j]);
				m.insert(conv(s1));
			}
		}
		printf("%d %d\n", *m.begin(),*m.rbegin());
	}


	return 0;
}
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
	cin>>s;

	int ans=0;
	char prev=s[0];
	int val=0;
	for(int i=0;i<s.length();i++) {
		if(s[i]==prev)
			val++;
		else {
			if(val%2==0)
				ans++;
			val=1;
		}
		prev=s[i];
	}
	if(val%2==0)
		ans++;
	printf("%d\n", ans);
	return 0;
}
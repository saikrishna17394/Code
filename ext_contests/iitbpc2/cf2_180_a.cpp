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
#define inf 1999999999
#define lim 10000000

using namespace std;

int main() {
	int n;

	cin>>n;

	string s;
	cin>>s;

	bool ok=true;
	for(int i=0;i<n;i++) {
		if(s[i]=='R') {
			printf("%d ",i+1);

			for(int j=i+1;j<n;j++) {
				if(s[j]=='.') {
					printf("%d\n",j+1);
					break;
				}
				if(s[j]=='L') {
					printf("%d\n", j);
					break;
				}
			}

			break;
		}
		if(s[i]=='L') {
			break;
		}
	}

	// cout<<"man\n";

	for(int i=0;i<n;i++) {
		if(s[i]=='R')
			break;

		if(s[i]=='L') {
			for(int j=n-1;j>=0;j--) {
				if(s[j]=='L') {
					printf("%d %d\n",j+1,i);
					break;
				}
			}
			break;
		}
	}

	return 0;
}
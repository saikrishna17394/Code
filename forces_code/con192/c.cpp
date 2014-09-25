#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n,r[100],c[100],val;
	string s[100];

	scanf("%d",&n);

	for(int i=0;i<n;i++)
		cin>>s[i];

	val=0;

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(s[i][j]=='.') {
				r[val++]=j;
				break;
			}
		}
	}

	if(val==n) {
		for(int i=0;i<n;i++)
			printf("%d %d\n",i+1,r[i]+1);
	}

	else {
		val=0;
		for(int j=0;j<n;j++) {
			for(int i=0;i<n;i++) {
				if(s[i][j]=='.') {
					c[val++]=i;
					break;
				}
			}
		}

		if(val==n) {
			for(int i=0;i<n;i++)
				printf("%d %d\n",c[i]+1,i+1);
		}
		else
			printf("-1\n");
	}

	return 0;
}
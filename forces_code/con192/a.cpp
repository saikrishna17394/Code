#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int r,c,ans=0;
	string s[10];

	scanf("%d %d",&r,&c);

	for(int i=0;i<r;i++)
		cin>>s[i];

	int val;

	for(int i=0;i<r;i++) {

		val=0;

		for(int j=0;j<c;j++)
			if(s[i][j]=='.')
				val++;

		if(val==c) {
			ans+=c;
			continue;
		}

		if(val==0)
			continue;
		int val1=0;
		for(int j=0;j<c;j++) {
			val1=0;

			if(s[i][j]=='.') {
				for(int k=0;k<r;k++)
					if(s[k][j]=='.')
						val1++;

				if(val1==r)
					ans++;
			}
		}

	}

	printf("%d\n",ans);
	return 0;
}
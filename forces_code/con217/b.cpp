#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 99999999
typedef long long int lli;

int main() {
	int n,m[100],A[100][101]={0},cnt[100],num;
	cin>>n;
	bool ok;

	for(int i=0;i<n;i++) {
		cin>>m[i];
		for(int j=0;j<m[i];j++) {
			cin>>num;
			A[i][num]=1;
		}
	}

	for(int i=0;i<n;i++) {
		memset(cnt,0,sizeof cnt);
		ok=false;

		for(int j=1;j<=100;j++) {
			if(A[i][j]) {
				for(int k=0;k<n;k++) {
					if(k==i)
						continue;
					if(A[k][j]) {
						cnt[k]++;
						if(cnt[k]==m[k])
							ok=true;
					}
				}
			}
		}
		if(ok)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
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

int n,A[100][100],cnt;
string s[100];
bool see(int i,int j) {
	if(i<0 || i>=n || j<0 || j>=n || A[i][j]!=0 || s[i][j]!='#')
		return false;
	return true;
}

bool check(int i,int j) {
	if(see(i,j+1) && see(i,j+2) && see(i-1,j+1) && see(i+1,j+1)) {
		A[i][j]=cnt;
		A[i][j+1]=cnt;
		A[i][j+2]=cnt;
		A[i-1][j+1]=cnt;
		A[i+1][j+1]=cnt;
		cnt++;
		return true;
	}
	if(see(i+1,j+1) && see(i+1,j) && see(i+1,j-1) && see(i+2,j)) {
		A[i][j]=cnt;
		A[i+1][j+1]=cnt;
		A[i+1][j]=cnt;
		A[i+1][j-1]=cnt;
		A[i+2][j]=cnt;
		cnt++;
		return true;
	}
	return false;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	memset(A,0,sizeof A);
	cnt=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(s[i][j]=='#' && A[i][j]==0) {
				// cout<<i<<" "<<j<<" "<<A[i][j]<<endl;
				if(!check(i,j)) {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	return 0;
}
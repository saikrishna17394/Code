#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

string A[100000];
int n;

int main(){ 
	cin.sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int j=0;j<A.length();j++) {
		if(j==0 && A[0][j]=='?')
			A[0][j]='1';
		else if(A[0][j]=='?')
			A[0][j]='0';
		else
			;
	}

	bool ok=true;
	for(int i=1;i<n;i++) {
		bool ok1=false;
		if(A[i].length()==A[i-1].length()) {
			for(int j=0;j<A[i].length();j++) {
				if(ok1) {
					if(A[i][j]=='?')
						A[i][j]='0';
					continue;
				}
				if(A[i][j]=='?') {
					if(A[i][])
				}
				else {
					if(A[i][j])
				}
			}
		}
		else {
			if(A[i][0]=='?')
				A[i][0]='1';
			for(int j=1;j<A[i].length();j++)
				if(A[i][j]=='?')
					A[i][j]='0';
		}
	}
	return 0;
}
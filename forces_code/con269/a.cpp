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

int A[6];

int main() {

	for(int i=0;i<6;i++) {
		cin>>A[i];
	}
	// cout<<"What\n";
	sort(A,A+6);

	int ans=-1;

	// bool ok1=true;
	for(int i=0;i<3;i++) {
		int val=A[i];
		bool ok=true;
		for(int j=i+1;j<i+4;j++) {
			if(A[j]!=val) {
				ok=false;
				break;
			}
		}
		if(!ok)
			continue;

		if(i==0) {
			if(A[4]!=A[5])
				ans=0;
			else
				ans=1;
		}
		else if(i==1) {
			if(A[0]!=A[5])
				ans=0;
			else
				ans=1;			
		}
		else {
			if(A[0]!=A[1])
				ans=0;
			else
				ans=1;			
		}
	}
	if(ans==1)
		printf("Elephant\n");
	else if(ans==0)
		printf("Bear\n");
	else
		printf("Alien\n");
	return 0;
}
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
	lli A[3],ans;
	for(int i=0;i<3;i++)
		cin>>A[i];

	ans=0;
	while(1) {
		sort(A,A+3);
		if(A[1]==0)
			break;
		if(A[0]==A[1]) {
			if(A[1]==A[2]) {
				ans+=A[0];
				break;
			}
			lli d=A[2]-A[1];
			if(d==1) {
				ans+=A[1];
				break;
			}
			ans+=2*min(d/2,A[1]);
			A[2]-=2*min(d/2,A[1]);
			A[1]-=min(d/2,A[1]);
			A[0]-=min(d/2,A[1]);
		}
		else {

			if(A[1]==A[2]) {
				lli d=A[1]-A[0];
				
			}
		}
	}
	return 0;
}
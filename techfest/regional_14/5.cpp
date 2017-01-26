#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <vector>
#define lli long long int
#define lim 1000200
#define mod1 1e18
#define ii pair<long long int,long long int>

using namespace std;
	lli A[lim];
	ii B[lim];
int main() {
	lli mod=mod1;
	A[0]=0;
	A[1]=1;
	for(lli i=2;i<lim;i++) {
		A[i]=(A[i-1]+A[i-2])%mod;
		if(A[i]<0)
			cout<<i<<endl;
	}
	int n=1000000;
	lli sm=mod,big=0;
	for(int i=0;i<n;i++) {
		sm=min(sm,A[i]);
		big=max(big,A[i]+A[i+100]);
		B[i]=ii(A[i],A[i]+A[i+100]);
		if(B[i].second<0)
			cout<<i<<endl;
	}
	cout<<sm<<" "<<big<<endl;
	mod=1000000007;

	sort(B,B+n);
	lli ans=0,start,end;
	start=B[0].first;
	end=B[0].second;


	// cout<<B[1].first<<" "<<start<<" "<<end<<endl;
	cout<<ans<<endl;
	for(int i=1;i<n;i++) {
		// cout<<start<<" "<<end<<endl;
		// cout<<B[i].first<<" "<<B[i].second<<endl;
		// cout<<i<<endl;
		if(B[i].first<=end)
			end=max(end,B[i].second);
		else {
			ans=ans+end-start+1;
			// ans%=mod;
			cout<<ans<<endl;
			start=B[i].first;
			end=B[i].second;
		}
	}
	// cout<<start<<End
	ans=ans+end-start+1;
	cout<<ans<<endl;
	cout<<ans%mod<<endl;

	return 0;
}
#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli d, d2;
lli fun_calls = 0;

lli solve(lli l, lli r, lli x, lli y) {
	// cout<< l  << " " << r<<endl;
	fun_calls ++ ;
	if(l == r)
		return (lli)2;

	lli A[2], B[2];
	A[0] = (l - d2)*(l - d2);
	A[1] = (r - d2)*(r - d2);

	B[0] = (x - d2)*(x - d2);
	B[1] = (y - d2)*(y - d2);

	lli mi = A[0] + B[0];
	lli ma = mi;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++) {
			mi = min(mi, A[i] + B[j]);
			ma = max(ma, A[i] + B[j]);
		}
	}

	// cout<<mi<<" "<<ma<<endl;
	// cout<<d<<endl;
	if(mi <= d && ma > d) {
		lli mid = (l + r)/2;
		lli mid1 = (x + y)/2;

		lli ret = 1 + solve(l,mid,x,mid1) + solve(mid+1,r,x,mid1);
		ret += solve(l,mid,mid1+1,y) + solve(mid+1,r,mid1+1,y);

		return ret;
	}
	return (lli)2;
}
int main() {
	d = 1 << 23;
	d = d * d;
	d2 = 1 << 23;

	lli val = 1 << 24;

	lli ans = 1;
	ans += solve(0, d2 - 1, 0, d2 - 1);
	ans += solve(d2, val - 1, 0, d2 - 1);
	ans += solve(0, d2 - 1, d2, val - 1);
	ans += solve(d2, val - 1, d2, val - 1);

	cout<<ans<<endl;
	cout<<fun_calls<<endl;sun
	return 0;
}
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

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	int n,A[100],ans,g;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	g=gcd(A[0],A[1]);

	for(int i=2;i<n;i++)
		g=gcd(g,A[i]);
	ans=g*n;
	cout<<ans<<endl;
	return 0;
}
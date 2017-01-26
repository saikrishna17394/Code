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
	lli n,m;
	cin>>n>>m;

	lli k=n-m+1;
	lli k_max=(k*(k-1))/2;

	lli val=n/m;
	lli rem=n%m;

	lli k_min=(m-rem)*(val*(val-1))/2;
	val++;
	// if(rem==0)
	// 	rem+=m;
	k_min+=rem*(val*(val-1))/2;

	cout<<k_min<<" "<<k_max<<endl;
}
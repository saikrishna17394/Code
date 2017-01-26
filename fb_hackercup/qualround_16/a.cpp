#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999

using namespace std;

int sq(int x) {
	return x*x;
}

int main() {
	freopen("progress_pie.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n;
	cin>>t;

	double pi = acos(0)*2.0;
	for(int a=1;a<=t;a++) {
		int p,x,y;

		cin >> p >> x >> y;
		double angle = p;
		angle /= 100.0;
		angle *= pi*2.0;

		printf("Case #%d: ",a);

		if(p == 0) {
			printf("white\n");
			continue;
		}


		if(sq(x-50) + sq(y-50) > 2500) {
			printf("white\n");
			continue;
		}
		
		pair<double, double> p1;


		p1.first = x - 50;
		p1.second = y - 50;


		double theta = 0;

		if(x == 50 & y == 50) {
			theta = 0.0;
		}
		else {
			theta = atan2(p1.first, p1.second);
		}

		if(theta < 0.0) {
			theta += pi*2.0;
		}

		// cout<< theta << " " << angle<<endl;
		if(theta <= angle) {
			printf("black\n");
		}
		else {
			printf("white\n");
		}
	}


	return 0;
}
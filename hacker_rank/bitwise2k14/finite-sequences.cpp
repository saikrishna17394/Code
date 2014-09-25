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

#define mod 1008
#define inf 999999999

using namespace std;

int main() {

	for(int i=1;i<64;i++) {
		int mask=i;
		int sum=0;
		for(int j=1;j<=6;j++) {
			if(mask&1)
				sum+=j;
			mask/=2;
		}
		// cout<<i<<" "<<sum<<endl;
		if(sum==6 ) {
			mask=i;
			int val=i&2;
			// cout<<i<<" kri "<<val<<sum<<endl;
			for(int j=1;j<=6;j++) {
				if(mask&1)
					cout<<j<<" ";
				mask/=2;
			}
			printf("\n");
		}
	}
	return 0;
}
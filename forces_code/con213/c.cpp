#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#define lim 50000001
using namespace std;

bool A[lim]={0};
int cnt[lim]={0};
vector<int> primes;
int main() {

	for(int i=2;i*i<lim;i++) {
		if(!A[i]) {
			for(int j=i*i;j<lim;j+=i)
				A[j]=1;
		}
	}

	for(int i=2;i<lim;i++) {
		if(primes[i]==)
	}

	return 0;
}
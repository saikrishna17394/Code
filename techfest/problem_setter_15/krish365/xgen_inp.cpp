#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define lim 100000
#define lim1 300001
using namespace std;

int main() {
	int n=100000;

	cout<<n<<endl;	
	for(int i=0;i<n;i++) {
		int num=rand()%lim;
		num++;
		int num1=rand()%lim1;
		cout<<"1 "<<n<<endl;
	}

	return 0;
}
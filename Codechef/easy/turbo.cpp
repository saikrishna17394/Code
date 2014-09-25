#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int t,A[1000000];
int partition(int p,int r) {
	int ind=(rand()%(r-p))+p;
	swap(A[ind],A[r]);
	int val=A[r];
	int i=p-1;

	int j=p;

	for(j=p;j<r;j++) {
		if(A[j]<=val) {
			i++;
			swap(A[i],A[j]);
		}
	}

	swap(A[i+1],A[r]);
	return i+1;
}

void quicksort(int i,int j) {
	if(i<j) {
		int ind=partition(i,j);
		bool val =true;
		for(int a=i;a<j;a++) {
			if(A[a]>A[a+1]) {
				val=false;
				break;
			}
		}

		if(val==true)
			return;
		quicksort(i,ind-1);
		quicksort(ind+1,j);
	}
}

int main() {
	inp(t);
	for(int i=0;i<t;i++)
		inp(A[i]);

	quicksort(0,t-1);

	for(int i=0;i<t;i++)
		printf("%d\n",A[i]);
	return 0;
}
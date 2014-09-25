#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>
#include <algorithm>
#define x getchar_unlocked()
using namespace std;

inline void inp( int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}


int main() {
	int t,n,k,num,ans,A[1000];
	inp(t);
	while(t--) {
		inp(n);
		inp(k);
		list<int> l; 

		for(int i=0;i<n;i++)
			inp(A[i]);
		
		ans=0;
		while(n) {
			num=0;
			for(int i=0;i<n;i++) {
				if(A[i]>=A[num])
					num=i;
			}

			while(num!=(n-1) ) {
				ans++;
				if((num+k)>=n) {
					int val=max(1,n-k+1);
					l.push_back(val);
					sort(A+val-1,A+n);
					num=n-1;
				}
				else {
					l.push_back(num+1);
					int val=min(num+k,n);
					sort(A+num,A+val);
					num=val-1;
				}
			}
			n--;
		}

		printf("%d\n",ans);
		for(list<int>::iterator it=l.begin();it!=l.end();it++)
			printf("%d ",*it);
		if(ans>0)
			printf("\n");

	}

	return 0;
}
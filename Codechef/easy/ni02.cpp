#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
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
int squ(int a,int b) {
	return a*a+b*b;
}

int main() {
	int t,n,a,b,c,d,sr;
	inp(t);
	int A[2502][2],D[2502];
	while(t--) {
		inp(n);
		for(int i=0;i<n+2;i++) {
			inp(A[i][0]);
			inp(A[i][1]);
			D[i]=inf;
		}

		D[n]=0;
		set<ii> s;

		s.insert(ii(0,n));

		while(!s.empty()) {
			ii top=*s.begin();
			s.erase(s.begin());

			int ind=top.second;
			if(ind==n+1)
				break;

			for(int i=0;i<n+2;i++) {
				//cout<<D[i]<<" ";
				int cost=squ(A[i][0]-A[ind][0],A[i][1]-A[ind][1]);
				
				if(D[i]>D[ind]+cost) {
					if(D[i]!=inf) 
						s.erase(ii(D[i],i));
					D[i]=D[ind]+cost;
					s.insert(ii(D[i],i));
				}			
			}
			//cout<<endl;

		}

		printf("%d\n",D[n+1]);


	}

	return 0;
}
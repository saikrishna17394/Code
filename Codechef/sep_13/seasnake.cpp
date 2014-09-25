#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int A[30][30]={0},n,m,a,b,steps=0;
int ans[900000];
pair<int,int> B[901];

int i,j,rt,dwn;

void next() {
	if(rt==1) {
		j=(j+1)%m;
		ans[steps++]=3;
	}
	else {
		j=(j-1+m)%m;
		ans[steps++]=2;
	}
}

void next1() {
	if(dwn==1) {
		i=(i+1)%n;
		ans[steps++]=1;
	}
	else {
		i=(i-1+n)%n;
		ans[steps++]=0;
	}
}

int main() {
	inp(n);
	inp(m);


	for(int k=1;k<n*m;k++) {
		inp(a);
		inp(b);
		B[k]=ii(a,b);
	}
	B[n*m]=ii(0,0);

	int cnt=1;


	A[B[cnt].first][B[cnt].second]=1;

	i=0,j=0,rt=1,dwn=1;

	if(m&1) {
		// cout<<i<<" "<<j<<endl;
		while(cnt<n*m) {
			// cout<<i<<" "<<j<<endl;
			if(n==1) {
				j=(j+1)%m;
				ans[steps++]=3;
			}
			else if(rt==1 && j==m-1 ) {
				i=(i+1)%n;
				rt=-1;
				ans[steps++]=1;
			}
			else if(rt==-1 && j==0) {
				i=(i+1)%n;
				rt=1;
				ans[steps++]=1;
			}
			else 
				next();

			if(A[i][j]==1) {
				cnt++;
				A[i][j]=0;
				A[B[cnt].first][B[cnt].second]=1;
			}

		}
	}

	else {
		while(cnt<n*m) {
			// cout<<i<<" "<<j<<endl;
			if(m==1) {
				i=(i+1)%n;
				ans[steps++]=1;
			}
			else if(dwn==1 && i==n-1) {
				j=(j+1)%m;
				dwn=-1;
				ans[steps++]=3;
			}
			else if(dwn==-1 && i==0) {
				j=(j+1)%m;
				dwn=1;
				ans[steps++]=3;
			}
			else 
				next1();

			if(A[i][j]==1) {
				cnt++;
				A[i][j]=0;
				A[B[cnt].first][B[cnt].second]=1;
			}

		}
	}
	
	printf("%d\n",steps);

	printf("%d",ans[0]);
	for(i=1;i<steps;i++)
		printf(" %d",ans[i]);
	printf("\n");

	return 0;
}
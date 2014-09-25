#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 99999999
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int t,A[15],B[15][15],val,a,b;
	int C[15][15][16];
	char ch1,ch2;
	inp(t);
	while(t--) {
		for(int i=0;i<15;i++)
			inp(A[i]);
		memset(C,0,sizeof C);

		for(int i=0;i<15;i++) {
			for(int j=0;j<15;j++)
				B[i][j]=inf;
		}

		for(int i=0;i<26;i++) {
			cin>>ch1;cin>>ch2>>val;
			//cout<<ch1<<" "<<ch2<<" "<<val<<endl;
			B[ch1-'A'][ch2-'A']=val+A[ch1-'A'];
			B[ch2-'A'][ch1-'A']=val+A[ch2-'A'];
		}


		for(int i=0;i<15;i++) {
			for(int j=0;j<15;j++)
				C[i][j][0]=B[i][j];
		}

		for(int k=1;k<=15;k++) {
			for(int i=0;i<15;i++) {
				for(int j=0;j<15;j++)
					C[i][j][k]=min(C[i][j][k-1],C[i][k][k-1]+C[k][j][k-1]);
			}		
		}
		cin>>ch1>>ch2;
		//scanf("%c %c",&ch1,&ch2);
		//cout<<ch1<<" "<<ch2<<endl;
		printf("%d\n",C[ch1-'A'][ch2-'A'][15]);
	}

	return 0;
}
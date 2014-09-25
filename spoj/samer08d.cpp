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

int main() {
	int t,A[1001][1001],B[1001][1001],k,len1,len2;
	char s1[1000],s2[1000],ch;

	inp(k);
	while(k) {
		len1=len2=0;

		ch=x;
		while(ch!='\n') {
			// cout<<ch<<endl;
			s1[len1++]=ch;
			ch=x;
		}

		ch=x;
		while(ch!='\n') {
			s2[len2++]=ch;
			ch=x;
		}

		for(int i=0;i<=len1;i++)
			A[i][0]=0,B[i][0]=0;

		for(int i=0;i<=len2;i++)
			A[0][i]=0,B[0][i]=0;

		for(int i=1;i<=len1;i++) {
			for(int j=1;j<=len2;j++) {
				if(s1[i-1]==s2[j-1])
					A[i][j]=A[i-1][j-1]+1;
				else
					A[i][j]=0;

				if(A[i][j]>=k) {
					B[i][j]=0;
					for(int a=0;a<=(A[i][j]-k);a++)
						B[i][j]=max(B[i][j],A[i][j] - a + B[ i-A[i][j]+a ][ j-A[i][j]+a ] );
				}
				else
					B[i][j]=max(B[i-1][j],B[i][j-1]);
			}
		}


		printf("%d\n",B[len1][len2]);
		inp(k);
	}

	return 0;
}
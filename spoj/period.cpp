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
	int n,A[1000000],t,i,len;
	char s[1000001];
	inp(t);

	for(int k=1;k<=t;k++) {
		printf("Test case #%d\n",k);

		inp(n);
		scanf("%s",s);

		A[0]=0;len=0;

		for(i=1;i<n;i++) {

			while(1) {
				if(s[i]==s[len]) {
					A[i]=++len;
					break;
				}
				else {
					if(len!=0)
						len=A[len-1];
					else {
						A[i]=0;
						break;
					}
				}
			}

			if(A[i]>0 &&(i+1)%(i+1-A[i])==0) {
				printf("%d %d\n",i+1,(i+1)/(i+1-A[i]));
			}
		}

		printf("\n");
	}

	return 0;
}
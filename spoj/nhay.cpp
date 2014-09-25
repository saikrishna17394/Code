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
	int n,*A,ans,i=0,j=0,len;
	string pat;

	char ch;

	while(scanf("%d\n",&n)!=EOF) {
		A=new int [n];

		pat="";
		ch=x;
		while(ch!='\n')
			pat+=ch,ch=x;
		A[0]=0;
		len=0;

		for(i=1;i<n;i++) {

			while(1) {
				if(pat[i]==pat[len]) {
					A[i]=++len;
					break;
				}
				else {
					if(len!=0) 
						len=A[len-1];
					else {
						A[i]=len;
						break;
					}
				}
			}
		}

		// for(int i=0;i<n;i++)
		// 	cout<<i<<" "<<A[i]<<endl;
		// cout<<"man\n";

		i=0;
		j=0;

		cin>>ch;

		while(ch!='\n') {
			// cout<<"Sai\n"<<i<<"\n";
			while(1) {
				// cout<<i<<" "<<j<<" "<<pat[i]<<" "<<ch<<" "<<A[i]<<endl;
				if(pat[i]==ch) {
					i++;
					break;
				}
				if(i==0) {
					break;
				}
				i=A[i-1];
			}

			j++;
			if(i==n) {
				printf("%d\n",j-n);	
				i=A[i-1];
			}
			ch=x;
		}

		printf("\n");
		delete [] A;
	}

	return 0;
}
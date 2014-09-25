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

string s,s1;
int A[10],cnt,t,num;

bool check(int n,int ind) {
	s1="";
	cnt=0;
	while(n!=0) {
		A[cnt++]=n%10;
		n/=10;
	}

	int k=s.length();
	for(int i=ind;i<k && cnt>=0;i++,cnt--) {
		if(A[cnt-1]!=s[i]-'0') {
			return false;
		}

	}
	return true;
}

bool big_check(int len) {
	for(int i=0;i<len;i++) {
		int ind=i;
		if(s[ind]=='0')
			continue;
		int num1=0,base=1;

		for(int j=0;j<len;j++) {
			num1+=(s[j+i]-'0')*base;
			base*=10;
		}
	}
}
int main() {
	inp(t);
	bool krish;
	while(t--) {
		krish=false;
		getline(cin,s);
		int k=s.length();
		if(k<=9 && s[0]>'0') {
			printf("YES\n");
			continue;
		}

		for(int i=1;i<=9;i++) {
			if(big_check(i)==true) {
				printf("YES\n");
				krish=true;
				break;
			}
		}

		if(krish==true)
			break;
	}
	return 0;
}
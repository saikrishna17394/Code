#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int conv(string s) {
	int ret=0;
	for(int i=0;i<7;i++) {
		ret*=2;
		ret+=s[i]-'0';
	}
	return ret;
}

void print(int num) {
	int val=64;

	for(int i=0;i<7;i++) {
		if(num>=val) {
			num-=val;
			printf("1");
		}
		else
			printf("0");
		val/=2;
	}
}

/*
 ABCDEFG
*/

string A[10]={
"1111110",
"0110000",
"1101101",
"1111001",
"0110011",
"1011011",
"1011111",
"1110000",
"1111111",
"1111011"
};

// 1011011
// 1011111
// 1010000
// 1011111
// 1011011
int B[10]={0},t,n;
string s;
int C[100];

int main() {

	for(int i=0;i<10;i++) {
		B[i]=conv(A[i]);
	}

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		int full=0;
		int rem=0;
		for(int i=0;i<n;i++) {
			cin>>s;
			C[i]=conv(s);
			// cout<<C[i]<<" ";
			full|=C[i];
		}

		int ans=-1,ans1=-1;
		for(int mask=0;mask<128;mask++) {
			if((mask|full)!=mask)
				continue;
			bool ok1=false;
			for(int k=0;k<10;k++) {
				int num=k;
				bool ok=true;
				for(int i=0;i<n;i++) {
					if((B[num]&mask)!=C[i]) {
						ok=false;
						break;
					}
					num--;
					if(num<0)
						num+=10;
				}
				if(!ok)
					continue;
				if(ans!=-1  && (ans!=(B[num]&mask)) ) {
					ans=-1;
					ok1=true;
					break;
				}
				ans=B[num]&mask;
			}
			if(ok1)
				break;
		}

		if(ans==-1) {
			printf("Case #%d: ERROR!\n", a);
		}
		else {
			printf("Case #%d: ",a );
			print(ans);
			printf("\n");
		}
	}
	return 0;
}
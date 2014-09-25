#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli unsigned long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

string s;
lli len;

void fun(lli num,lli l,lli x) {
	if(l==1) {
		printf("%c",s[num-1] );
		return;
	}

	for(int i=0;i<len;i++) {
		if(num>x)
			num-=x;
		else {
			printf("%c",s[i]);
			x/=len;
			fun(num,l-1,x);
			return;
		}
	}
}

int main() {
	freopen("labelmaker_example_input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	lli t,num1;
	lli num,l,x;

	inp(t);

	for(int a=1;a<=t;a++) {
		cin>>s;
		inp(num);
		len=s.length();
		l=0;
		x=1;

		while(1) {
			num1=num;
			for(int i=0;i<len;i++) {
				if(num>x)
					num-=x;
				else
					break;
			}
			l++;
			if(num<=x)
				break;
			x=x*len;
		}
		// cout<<num1<<" "<<l<<" "<<x<<endl;
		printf("Case #%d: ",a);
		fun(num1,l,x);
		printf("\n");
	}
	return 0;
}
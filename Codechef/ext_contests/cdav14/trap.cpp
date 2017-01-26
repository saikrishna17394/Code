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
#define ii pair<int,int>

#define mod 1008
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

int A[300],idx=0;

int main() {
	string s;
	getline(cin,s);

	for(int i=0;i<s.length();i++) {
		if(s[i]=='(')
			A[idx++]=1;
		else if(s[i]=='{')
			A[idx++]=2;
		else if(s[i]==')') {
			if(idx>0 && A[idx-1]==1) {
				idx--;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
		else if(s[i]=='}') {
			if(idx>0 && A[idx-1]==2) {
				idx--;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
		else {
			;
		}
	}

	if(idx==0)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
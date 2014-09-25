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
int t,len;
char A[100001];
int B[1000001];

int find(int i) {
	if(i+1==len) {
		B[i]=-1;
		return 0;
	}
	if(A[i]=='7') {
		B[i]=-1;
		return 0;
	}

	if(A[i]=='4' && A[i+1]=='7') {
		B[i]=0;
		return 1;
	}

	B[i]=-1;
	int p;
	for(int j=i+1;j<len;j++) {
		p=find(j);
		if(B[j]==-1) {
			if(A[j]=='7')
				
			j+=p;
			return (j-i);
		}
		j+=p;


	}
}
int main() {
	lli ans;
	while(t--) {
		inp(len);
		scanf("%s",A);

		for(int i=0;i<len;i++) {
			i+=find(i);
		}


		ans=0;

	}

	return 0;
}
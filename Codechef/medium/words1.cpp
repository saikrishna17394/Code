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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int A[26],B[26],num,mark[26],cnt,num1,pos;
int g[26][26];

void dfs(int i) {
	mark[i]=1;

	for(int j=0;j<26;j++) {
		if(g[i][j]==1 && mark[j]==0)
			dfs(j);
	}

}
int main() {
	char a,b,ch;
	int t,n;

	inp(t);

	while(t--) {
		inp(n);

		// Connectedness is also necessary
		// Use set union data structure
		
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		memset(mark,0,sizeof mark);
		memset(g,0,sizeof g);
		for(int i=0;i<n;i++) {
			
			a=getchar_unlocked();
			ch=b=a;

			while(ch!='\n') {
				b=ch;
				ch=getchar_unlocked();
			}

			a=a-'a';
			b=b-'a';
			if(a!=b) {
				g[a][b]=1;
				g[b][a]=1;
			}
			A[a]++;
			B[b]++;

		}
		num=0;
		num1=0;
		pos=26;
		for(int i=0;i<26;i++) {
			// cout<<i<<" "<<A[i]<<" "<<B[i]<<endl;
			if(A[i]==B[i])
				continue;
			if(A[i]==B[i]+1)
				num++;
			else if(B[i]==A[i]+1)
				num1++;
			else {
				pos=i;
				break;
			}
		}

		if(pos<26 || !(num==num1 && num<=1)) {
			printf("The door cannot be opened.\n");
			continue;
		}

		cnt=0;
		for(int i=0;i<26;i++) {
			// cout<<i<<" "<<A[i]<<" "<<mark[i]<<endl;
			if((A[i]>0 || B[i]>0)&& mark[i]==0) {
				cnt++;
				if(cnt==2)
					break;
				dfs(i);
			}
		}

		// cout<<cnt<<endl;
		if(cnt==2) {
			printf("The door cannot be opened.\n");
			continue;
		}
	
		printf("Ordering is possible.\n");	
	}


	return 0;
}
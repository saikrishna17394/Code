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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000100

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[1<<20];

int main() {
	int t;
	string s;

	inp(t);

	while(t--) {
		cin>>s;
		// memset(A,0,sizeof A);
		int n=s.length();
		int num=n;
		for(int i=0;i<n;i++)
			A[i]=0;
		
		bool ok=true;
		int idx=0;
		while(num>1) {
			if(num%2==1) {
				ok=false;
				break;
			}
			num/=2;
			idx++;
		}

		if(!ok || n==1) {
			printf("INVALID\n");
			continue;
		}
		// cout<<"man "<<idx<<endl;;
		num=0;
		for(int i=0;i<idx;i++) {
			num*=2;
			if(s[i]=='1')
				num++;
		}

		A[num]=1;

		// cout<<"0 : "<<num<<endl;
		for(int i=1;i<n;i++) {
			num*=2;
			if(s[(i+idx-1)%n]=='1')
				num++;
			if(s[i-1]=='1')
				num^=n;
			A[num]=1;
			// cout<<i<<" : "<<num<<endl;
		}

		for(int i=0;i<n;i++) {
			if(A[i]==0) {
				ok=false;
				break;
			}
		}
		if(ok)
			printf("VALID\n");
		else
			printf("INVALID\n");
	}
	return 0;
}
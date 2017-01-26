#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


string s;
int n;

int A[100000],idx;

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>s;
	n=s.length();

	idx=0;

	int val=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='(')
			val++;
		else if(s[i]==')')
			val--;
		else {
			A[idx++]=1;
			val--;
		}
		if(val<0) {
			printf("-1\n");
			return 0;
		}
	}
	A[idx-1]+=val;
	val=0;
	int cnt=0;

	for(int i=0;i<n;i++) {
		if(s[i]=='(')
			val++;
		else if(s[i]==')')
			val--;
		else 
			val-=A[cnt++];
		if(val<0) {
			printf("-1\n");
			return 0;
		}
	}
	for(int i=0;i<idx;i++)
		printf("%d\n", A[i]);

	return 0;
}
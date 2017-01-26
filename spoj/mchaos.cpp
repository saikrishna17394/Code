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
#define lli long long int
#define ii pair<int,int>

#define mod 5000000
#define inf 999999999
#define lim 100000
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int tree[lim+1]={0},n;
string A[lim];
pair<lli,int> B[lim];
int pos[lim];

void upd(int idx,int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

string rev(string s) {
	string ret="";
	for(int i=s.size()-1;i>=0;i--)
		ret+=s[i];
	return ret;
}

lli hash_rev(string s) {
	lli ret=0;
	for(int i=s.length()-1;i>=0;i--) {
		ret*=27;
		ret+=s[i]-'a'+1;
	}
	for(int i=s.length();i<10;i++)
		ret*=27;
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin>>n;

	// map<string,int> m;

	for(int i=0;i<n;i++) {
		cin>>A[i];
		// B[i]=rev(A[i]);
		// m[B[i]]=i;
	}

	sort(A,A+n);

	for(int i=0;i<n;i++){
		long long int hash=hash_rev(A[i]);
		B[i]=make_pair(hash,i);
	}
	sort(B,B+n);

	for(int i=0;i<n;i++) {
		pos[B[i].second]=i;
	}

	lli ans=0;
	for(int i=0;i<n;i++) {
		int idx=pos[i];
		ans+=(lli)(i-read(idx+1));
		upd(idx+1,1);
	}

	printf("%lld\n", ans);
	return 0;
}
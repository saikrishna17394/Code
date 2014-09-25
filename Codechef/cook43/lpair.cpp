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
#include <ctime>

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

int n,a,b,tree[100001]={0},tree1[100001]={0};
// ii A[100000];
map<int,int> f,m,m1;

void update(int idx,int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

int sum(int idx) {
	int ret=0;
	while(idx) {
		ret+=tree[idx];
		idx-=(idx&-idx);
	}
	return ret;
}
int main() {
	inp(n);

	for(int i=0;i<n;i++) {
		inp(a);
		inp(b);

		m1[a]=b;
		m[a]=0;
		f[b]=0;
	}

	int cnt=1;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		it->second=cnt++;
	}
	
	cnt=1;
	for(map<int,int>::iterator it=f.begin();it!=f.end();it++) {
		it->second=cnt++;
	}

	for(int i=1;i<=n;i++) {
		tree[i]=(i&-i);
		// cout<<i<<" "<<tree1[i]<<endl;
	}

	lli ans=0;
	for(map<int,int>::reverse_iterator it=m1.rbegin();it!=m1.rend();it++) {
		int idx=f[it->second];
		update(idx,-1);
		int val=sum(idx);
		val=sum(n)-sum(idx);
		ans+=(lli)val;
	}
	// cout<<tree[1]<<" "<<tree[2]<<" "<<tree[2]<<
	
	printf("%lld\n", ans);
	return 0;
}
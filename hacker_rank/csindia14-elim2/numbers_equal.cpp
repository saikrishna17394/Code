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
int n,A[100000];
int tree[400000];
lli k;
vector<int> v[100001];


void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx]=A[l];
		// cout<<idx<<" nayna "<<tree[idx]<<endl;
		return;
	}
	int mid=(l+r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	tree[idx]=max(tree[2*idx],tree[2*idx+1]);
	// cout<<idx<<" nayna "<<tree[idx]<<endl;
}

int query(int idx,int l,int r,int i,int j) {

	if(i>j) {
		// cout<<i<<"q  "<<j<<" 0"<<endl;
		// cout<<l<<" --- "<<r<<endl<<endl;
		return 0; 
	}
	if(l==i && r==j) {
		// cout<<i<<"q  "<<j<<" "<<tree[idx]<<endl;
		// cout<<l<<" --- "<<r<<endl<<endl;
		return tree[idx];
	}
	int mid=(l+r)/2;

	int ret= max(query(2*idx,l,mid,i,min(mid,j)),
		query(2*idx+1,mid+1,r,max(i,mid+1),j));
	// cout<<i<<"q  "<<j<<" "<<ret<<endl;
	// cout<<l<<" --- "<<r<<endl<<endl;
	return ret;
}

lli solve(int i,int j) {
	if(i==j) {
		return 0;
	}
	int big=query(1,0,n-1,i,j);
	lli ret=0;

	vector<int>::iterator it=upper_bound(v[big].begin(),v[big].end(),i-1);

	// cout<<big<<" w "<<endl;
	int prev=i;
	while(it!=v[big].end()) {
		int cur=*it;
		// cout<<"bro "<<cur <<" "<<prev<<endl;
		if(cur>j)
			break;
		if(cur>prev) {
			// cout<<"what "<<big<<" "<<prev<<" "<<cur-1<<endl;
			// cout<<query(1,0,n-1,prev,cur-1)<<" fu"<<endl;

			ret+=(lli)(big-query(1,0,n-1,prev,cur-1));
			ret+=solve(prev,cur-1);
		}
		prev=cur+1;
		it++;
	}
	if(prev<=j) {
		ret+=(lli)(big-query(1,0,n-1,prev,j));
		ret+=solve(prev,j);		
	}
	// cout<<i<<" solve "<<j<<" "<<ret<<endl;
	return ret;
}

int main() {
	inp(n);
	cin>>k;

	for(int i=0;i<n;i++) {
		inp(A[i]);
		v[A[i]].push_back(i);
	}

	build(1,0,n-1);

	lli val=solve(0,n-1);
	// cout<<query(1,0,n-1,0,0)<<" fu"<<endl;
	// lli val=0;
	lli ans=0;

	// cout<<val<<"ff  "<<k<<endl;
	if(val<=k) {
		ans++;
		ans+=(k-val);
	}
	printf("%lld\n", ans);
	return 0;
}
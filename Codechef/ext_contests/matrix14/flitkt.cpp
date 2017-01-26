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
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
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

int t,n;
int tree[5001];

void upd(int idx,int val) {
	while(idx<=5000) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int query(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

pair<string,string> A[10000];
int par[20000],B[20000];
string s[20000];

int main() {
	// freopen("inp","r",stdin);

	// freopen("C-small-attempt0.in", "r", stdin);	
	// freopen("C-large.in", "r", stdin);	

	// freopen("out.txt", "w", stdout);


	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		map<string,int> m;
		m.clear();

		for(int i=0;i<n;i++) {
			cin>>A[i].first>>A[i].second;
			m[A[i].first]=1;
			m[A[i].second]=1;
		}

		int idx=0;
		for(map<string,int>::iterator it=m.begin();it!=m.end();it++) {
			par[idx]=-1;
			B[idx]=-1;
			s[idx]=it->first;
			it->second=idx++;
		}

		for(int i=0;i<n;i++) {
			int x=m[A[i].first];
			int y=m[A[i].second];
			par[y]=x;
			B[x]=y;
		}
		
		int ans=-1;
		for(int i=0;i<idx;i++) {
			if(par[i]==-1)
				ans=i;
		}

		// printf("Case #%d:",a);

		while(B[ans]!=-1) {
			cout<<s[ans]<<"-"<<s[B[ans]];
			printf(" ");
			ans=B[ans];
		}
		printf("\n");
	}


	return 0;
}
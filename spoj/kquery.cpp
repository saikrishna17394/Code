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
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[30002],B[30002],n,q,a,b,k;
int ans[200000];
vector<ii> v[30001];
int tree[30002]={0};

void upd(int idx,int val) {
	// cout<<idx<<" upd "<<val<<endl;
	while(idx<=(n+1)) {
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


int main() {
	inp(n);
	for(int i=1;i<=n;i++) {
		inp(A[i]);
		B[i]=A[i];
	}
	sort(A+1,A+n+1);
	inp(q);

	for(int i=0;i<q;i++) {
		inp(a);
		inp(b);
		inp(k);
		v[a-1].push_back(ii(-k,i));
		v[b].push_back(ii(k,i));
	}

	for(int i=1;i<=n;i++) {
		upd((lower_bound(A+1,A+n+1,B[i])-A),1);

		for(int j=0;j<v[i].size();j++) {
			if(v[i][j].first>0) {
				int pos=lower_bound(A+1,A+n+1,v[i][j].first)-A;
				if(pos!=(n+1) && A[pos]>v[i][j].first)
					pos--;
				ans[v[i][j].second]+=(i-query(pos));
				// cout<<v[i][j].second<<" + "<<pos<<" "<<query(pos)<<endl;
			}
			else {
				int pos=lower_bound(A+1,A+n+1,-v[i][j].first)-A;
				if(pos!=(n+1) && A[pos]>(-v[i][j].first))
					pos--;
				ans[v[i][j].second]-=(i-query(pos));				
				// cout<<v[i][j].second<<" - "<<pos<<" "<<query(pos)<<endl;
			}
		}
	}

	for(int i=0;i<q;i++)
		printf("%d\n", ans[i]);
	return 0;
}

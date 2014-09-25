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

// Solved it with some greedy topcoder forum solution previously
// But now it can be solved simply by BIT :')

int tree[100001],t,n,a,b,c;
pair<int,ii> A[100000];

int query(int idx) {
	int ret=inf;
	while(idx>0) {
		ret=min(tree[idx],ret);
		idx-=idx&-idx;
	}
	return ret;
}

void update(int idx,int val) {
	while(idx<=n) {
		tree[idx]=min(tree[idx],val);
		idx+=idx&-idx;
	}
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(int i=0;i<n;i++) {
			inp(a);
			inp(b);
			inp(c);
			A[i]=make_pair(a,ii(b,c));
		}
		sort(A,A+n);

		fill(tree,tree+n+1,inf);
		int ans=0;

		for(int i=0;i<n;i++) {
			ii p=A[i].second;

			if(query(p.first-1)>p.second)
				ans++;
			update(p.first,p.second);
		}
		printf("%d\n", ans);
	}



	return 0;
}

// int main() {
// 	int t,n,a,b,c,ans;
// 	pair<int,ii> A[100000];
// 	set<ii> s;
// 	vector<ii> v;
// 	inp(t);

// 	while(t--) {
// 		inp(n);

// 		for(int i=0;i<n;i++) {
// 			inp(a);
// 			inp(b);
// 			inp(c);
// 			A[i]=make_pair(c,ii(a,b));
// 		}

// 		sort(A,A+n);
		
// 		s.clear();
// 		s.insert(A[0].second);
// 		ans=1;
// 		ii p;
// 		for(int i=1;i<n;i++) {
// 			p=A[i].second;
// 			set<ii>::iterator it=s.lower_bound(ii(p.first,0));
			
// 			v.clear();
// 			if(it!=s.begin()) {
// 				it--;
// 				if((it->second)<(p.second))
// 					continue;
// 			}

// 			ans++;
			
// 			v.clear();
			
// 			for(it=s.lower_bound(p);it!=s.end();it++) {
// 				if((p.second)>(it->second))
// 					break;
// 				v.push_back(*it);
// 			}
			
// 			s.insert(p);
			
// 			for(int j=0;j<v.size();j++)
// 				s.erase(v[j]);

// 		}
// 		printf("%d\n", ans);
// 	}

// 	return 0;
// }
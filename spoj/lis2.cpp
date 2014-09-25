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

// Solved it with some greedy solution by xorfires
// But now it can be solved simply by BIT :')
int A[100000],n;
int tree[100001]={0};
map<int,int> m;

int main() {
	inp(n);

	for(int i=0;i<n;i++) {
		inp(A[i]);
		m[A[i]]=1;
	}

	int idx=1;

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
		it->second=idx++;

	for(int i=0;i<n;i++) {
		update(m[A[i]],)
	}


	return 0;
}





// bool cmp(ii a,ii b) {
// 	if(a.first<b.first)
// 		return true;
// 	if(a.first==b.first)
// 		return a.second>b.second;
// 	return false;
// }

// set < pair <int, int> > s[100006];
 
// int main()
// {
// 	int n; scanf("%d", &n);

// 	for (int i = 0; i < n; i++)
// 	{
// 		int x, y; scanf("%d%d", &x, &y);

// 		int lo = 0, hi = n;
// 		while (lo < hi)
// 		{
// 			int mi = (lo + hi + 1) / 2;
// 			if (s[mi].empty()) { hi =  mi - 1; continue; }

// 			set < pair <int, int> >::iterator it = s[mi].lower_bound(make_pair(x, y));
// 			if (it == s[mi].begin()) { hi = mi - 1; continue; }
// 			it--;

// 			if (it->first == x and it == s[mi].begin()) { hi = mi - 1; continue; }
// 			else if (it->first == x) it--;

// 			// assert(it->first < x);
// 			if (it->second < y) lo = mi;
// 			else hi = mi - 1;
// 		}
// 		lo++;

// 		set < pair <int, int> >::iterator start, end;
// 		start = s[lo].lower_bound(make_pair(x, y));
// 		if (start != s[lo].begin())
// 		{
// 			start--;
// 			if (start->first == x) continue;
// 			else start++;
// 		}
// 		end = start;
// 		while (end != s[lo].end() and end->second > y) end++;

// 		s[lo].erase(start, end);
// 		s[lo].insert(make_pair(x, y));
// 	}

// 	int ret = 1;
// 	for (int i = 1; i <= n; i++)
// 		if (!s[i].empty())
// 			ret = i;
// 	printf("%d\n", ret);
// 	return 0;
// }
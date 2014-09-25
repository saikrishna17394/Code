#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
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
int n,m,k,val,len,ans,val1,A[200000];
vector<ii> v[100001],v1[100001];

int find(int pos,int i,int j,int val) {
	// cout<<i<<" kri "<<j<<" "<<pos<<endl;
	if(i==j) {
		// cout<<"dude\n";
		// cout<<v1[pos].size()<<endl;
		if(val>=v1[pos][i].second) {
			// cout<<"nayna\n";
			// cout<<v1[pos][i].first<<endl;
			return v1[pos][i].first;
		}
		else
			return 0;
	}
	int mid=(i+j)/2+1;

	if(val==v1[pos][mid].second)
		return v1[pos][mid].first;
	if(val>v1[pos][mid].second)
		return find(pos,mid,j,val);

	return find(pos,i,mid-1,val);

}

int main() {
	inp(n);
	inp(m);
	inp(k);
	ii p;
	inp(A[0]);
	v[A[0]].push_back(ii(0,0));

	for(int i=1;i<n;i++) {
		inp(A[i]);
		if(A[i]==A[i-1]) {
			len=v[A[i]].size();
			p=v[A[i]][len-1];
			v[A[i]][len-1]=ii(p.first,i);
		}
		else {
			v[A[i]].push_back(ii(i,i));
		}
	}
	ans=0;
	// cout<<"due\n";
	for(int i=1;i<=m;i++) {
		if(v[i].size()==0)
			continue;
		len=v[i].size();
		v1[i].push_back(ii(v[i][0].second-v[i][0].first+1,0));
		for(int j=1;j<len;j++) {
			v1[i].push_back(ii(v[i][j].second-v[i][j].first+1+v1[i][j-1].first,v1[i][j-1].second+v[i][j].first-v[i][j-1].second-1));
		}
		int val=k,val1=0;
		for(int j=0;j<len;j++) {
			// cout<<i<<" aa "<<" "<<j<<endl;
			// cout<<i<<" "<<v1[i][j].first<<" "<<v1[i][j].second<<endl;
			val=k+v1[i][j].second;
			ans=max(ans,find(i,j,len-1,val)-val1);
			// cout<<"krish\n";
			val1=v1[i][j].first;
			// cout<<"kri1\n";
		}
		// cout<<"ass\n";
	}
	printf("%d\n", ans);
	return 0;
}
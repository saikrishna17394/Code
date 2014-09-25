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

int vis[1000],val[1000],par[1000];
string ans[501];

string rev(string s) {
	string ret="";
	for(int i=s.size()-1;i>=0;i--)
		ret+=s[i];
	return ret;
}

int main() {
	int t,n;

	for(int i=1;i<=500;i++) {
		int node=0,ver,ptr;
		memset(vis,0,sizeof vis);
		vis[9%i]=1;
		val[node]=9;
		par[node]=-1;
		queue<ii> q;
		q.push(ii(9%i,node));
		node++;


		// cout<<i<<" : \n";
		while(!q.empty()) {
			ii p=q.front();
			// cout<<p.first<< "  "<<p.second<<endl;
			ver=p.first;
			if(ver==0) {
				ptr=p.second;
				break;
			}

			q.pop();

			int r=(ver*10)%i;
			if(vis[r]==0) {
				vis[r]=1;
				val[node]=0;
				par[node]=p.second;
				q.push(ii(r,node));
				node++;
			}
			r=(r+9)%i;
			if(vis[r]==0) {
				vis[r]=1;
				val[node]=9;
				par[node]=p.second;
				q.push(ii(r,node));
				node++;
			}
		}

		ans[i]="";
		while(1) {
			// cout<<ptr<<" "<<par[ptr]<<endl;
			ans[i]+=('0'+val[ptr]);
			ptr=par[ptr];
			if(ptr==-1)
				break;
		}
		ans[i]=rev(ans[i]);
		// cout<<i<<" "<<ans[i]<<endl<<endl;
	}
	inp(t);

	while(t--) {
		inp(n);
		cout<<ans[n]<<endl;
	}

	return 0;
}
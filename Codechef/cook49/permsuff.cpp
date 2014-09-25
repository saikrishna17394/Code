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
int t,n,m,A[100001],par[100001];
ii B[100000];

vector<ii> v;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=1;i<=n;i++)
			inp(A[i]);

		for(int i=0;i<m;i++) {
			inp(B[i].first);
			inp(B[i].second);
		}

		sort(B,B+m);
		v.clear();

		int l=B[0].first,r=B[0].second;

		for(int i=1;i<m;i++) {
			if(B[i].first<=r)
				r=max(B[i].second,r);
			else {
				v.push_back(ii(l,r));
				l=B[i].first;
				r=B[i].second;
			}
		}
		v.push_back(ii(l,r));

		int idx=0,cnt=v.size();

		// for(int i=0;i<v.size();i++)
		// 	cout<<v[i].first<<" "<<v[i].second<<endl;
		// cout<<"uo\n";
		// par[1]=idx;
		int num=0;

		int i=1;


		while(i<=n) {
			// cout<<i<<" "<<idx<<" "<<cnt<<endl;
			if(idx<cnt) {
				// cout<<"man "<<i<<" "<<idx<<" "<<endl;
				if(i<v[idx].first)
					par[i]=++num;
				else if(i>v[idx].second)
					par[i]=++num;
				else {
					num++;
					for(int j=v[idx].first;j<=v[idx].second;j++)
						par[j]=num;
					i=v[idx].second;
					// cout<<"bro "<<i<<endl;
					idx++;
				}
			}
			else {
				par[i]=++num;
			}
			i++;
		}

		// for(int i=1;i<=n;i++) {
		// 	cout<<i<<" "<<par[i]<<endl;
		// }

		bool ok=true;

		for(int i=1;i<=n;i++) {
			if(par[i]!=par[A[i]]) {
				ok=false;
				break;
			}
		}

		if(ok)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}

	return 0;
}
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
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

#define rtr(container, it) \
for(typeof(container.rbegin()) it = container.rbegin(); it != container.rend(); it++) 

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,m,p,w;
lli S[100];


int main() {
	// freopen("inp","r",stdin);
	// freopen("A-small-attempt0.in", "r", stdin);	
	freopen("A-large.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(p);
		for(lli i=0;i<p;i++)
			inp(S[i]);
		inp(n);
		map<string,vector<lli> > M;

		while(n--) {
			inp(w);
			for(lli i=0;i<p;i++) {
				string s;
				cin>>s;
				M[s].push_back(w*S[i]);
			}
		}

		inp(m);

		map<lli,set<string> > M1;
		tr(M,it) {
			vector<lli> v=it->second;
			sort(v.begin(),v.end());

			lli val=0;
			for(lli i=0;i<min((lli)v.size(),m);i++) {
				val+=v[(lli)v.size()-i-1];
			}
			M1[val].insert(it->first);
		}

		int pos=1;

		printf("Case #%d:\n", a);
		rtr(M1,it) {
			// cout<<it->first<<endl;
			int pos1=pos;
			tr(it->second,it1) {
				printf("%d: ",pos1 );
				pos++;
				cout<<*it1<<endl;
			}
		}
	}


	return 0;
}
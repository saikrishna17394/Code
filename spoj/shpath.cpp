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

int main() {
	int t,n,r,n1,a,b,src,dest,ver,cost,cost1,ver1;
	char ch;
	ii top;
	string s;

	vector<ii> g[10001];
	priority_queue<ii,vector<ii>,greater<ii> > Q;
	int D[10001];
	map<string,int> m;

	inp(t);

	while(t--) {
		inp(n);

		m.clear();

		for(int i=1;i<=n;i++) {
			s="";
			ch=getchar_unlocked();
			while(ch!='\n') {
				s+=ch;
				ch=getchar_unlocked();
			}
			m[s]=i;
			// cout<<s<<" "<<m[s]<<endl;
			g[i].clear();
			inp(n1);

			for(int j=0;j<n1;j++) {
				inp(a);
				inp(b);
				g[i].push_back(ii(a,b));

			}
		}

		inp(r);
		// cout<<r<<endl;
		while(r--) {

			s="";
			ch=getchar_unlocked();
			while(ch!=' ') {
				s+=ch;
				ch=getchar_unlocked();
			}
			src=m[s];
			// cout<<s<< " ayya "<<src<<endl;

			s="";
			getline(cin,s);
			// ch=getchar_unlocked();
			// while(ch!='\n') {
			// 	s+=ch;
			// 	ch=getchar_unlocked();
			// }
			dest=m[s];
			// cout<<s<<" "<<dest<<endl;
			for(int i=1;i<=n;i++)
				D[i]=inf;

			while(!Q.empty())
				Q.pop();

			Q.push(ii(0,src));
			D[src]=0;

			while(!Q.empty()) {
				top=Q.top();
				Q.pop();

				ver=top.second;
				cost=top.first;
				// cout<<dest<<" "<<ver<<" "<<D[ver]<<endl;
				if(ver==dest)
					break;

				if(cost<=D[ver]) {
					for(int i=0;i<g[ver].size();i++) {
						ver1=g[ver][i].first;
						cost1=g[ver][i].second;

						// cout<<ver1<<" "<<D[ver1]<<" "<<cost+cost1<<endl;
						if(D[ver1]>cost+cost1) {
							D[ver1]=cost+cost1;
							Q.push(ii(D[ver1],ver1));
						}
					}
				}
			}

			printf("%d\n",D[dest]);

		}

	}


	return 0;
}
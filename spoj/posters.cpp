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
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}
ii A[40000];
int t,n,ans,B[40000];
set<ii> s;
map<ii,int> m;

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
			A[i].first--;
			B[i]=0;
		}

		// ans=1;
		s.clear();
		m.clear();
		
		m[A[0]]=0;

		s.insert(A[0]);
		// s.insert(A[0].second);

		for(int i=1;i<n;i++) {
			int num=s.rbegin()->second;

			if(A[i].first>=num) {
				s.insert(A[i]);
				m[A[i]]=i;
				continue;
			}

			num=s.begin()->first;

			if(A[i].second<=num) {
				s.insert(A[i]);
				m[A[i]]=i;
				continue;
			}

			// cout<<i<<" yay\n";
			vector<ii> v;
			vector<ii> v1;

			// v.clear();
			// v1.clear();


			set<ii>::iterator it,it1;

			it=s.lower_bound(ii(A[i].first,0));

			if(it==s.end())
				it--;
			else if(it->first != (s.begin()->first) )
				it--;
			else
				;

			while(it!=s.end()) {
				if(it->second<=A[i].first) {
					it++;
					continue;
				}

				if(it->first>=A[i].second)
					break;

				if(it->first<A[i].first) {
					// cout<<"what  ";
					v1.push_back(ii(it->first,A[i].first));
					m[ii(it->first,A[i].first)]=m[*it];
					// cout<<it->first<<" "<<A[i].first<<"man\n";
				}

				if(A[i].second < it->second) {
					// cout<<"what  ";
					v1.push_back(ii(A[i].second,it->second));
					m[ii(A[i].second,it->second)]=m[*it];	
					// cout<<A[i].second<<" "<<it->second<<"man\n";
				}
				v.push_back(*it);

				it++;
			}


			m[A[i]]=i;
			s.insert(A[i]);

			for(int j=0;j<v.size();j++) {
				// cout<<"--------- "<<i<<endl;
				// cout<<v[j].first<<" "<<v[j].second<<endl;
				s.erase(v[j]);
				m.erase(v[j]);
				// cout<<"--------- "<<i<<endl;
			}

			for(int j=0;j<v1.size();j++) {
				// cout<<"--------- "<<i<<endl;
				// cout<<v[j].first<<" "<<v[j].second<<endl;
				s.insert(v1[j]);
				// m.erase(v[j]);
				// cout<<"--------- "<<i<<endl;
			}

		}

		ans=0;
		// memset(B,0,sizeof B);

		for(map<ii,int>::iterator it=m.begin();it!=m.end();it++) {
			// cout<<(it->first).first<<" "<<(it->first).second<<" "<<it->second<<endl;
			B[it->second]=1;
		}

		for(int i=0;i<n;i++)
			if(B[i])
				ans++;

		printf("%d\n", ans);

	}
	return 0;
}

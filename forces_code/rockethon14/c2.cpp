#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;

set<ii> s[200010];
int p[200001],e[200001];
set<ii> s1,s2;

int main() {
	int n,k;

	scanf("%d %d",&n,&k);

	for(int i=0;i<n;i++) {
		scanf("%d %d",&p[i],&e[i]);
		s[p[i]].insert(ii(e[i],i));
		s1.insert(ii(e[i],i));
	}

	int bet=n;
	lli inf=(lli)1e18;
	lli ans=inf;

	int cur=s[0].size();
	
	for(set<ii>::iterator it=s[0].begin();it!=s[0].end();it++) {
		s2.insert(*it);
	}
	// cur+=s[1].size();


	for(int pts=0;pts<=n;pts++) {
		// cout<<"yay : "<<pts<<endl;
		if(pts>1) {
			cur-=s[pts-2].size();
			bet-=(int)s[pts-2].size();
			for(set<ii>::iterator it=s[pts-2].begin();it!=s[pts-2].end();it++) {
				s2.erase(*it);
			}
		}

		cur+=s[pts+1].size();
		for(set<ii>::iterator it=s[pts+1].begin();it!=s[pts+1].end();it++) {
			s2.insert(*it);
		}

		cur=s2.size();

		// for(set<ii>::iterator it=s2.begin();it!=s2.end();it++) {
		// 	// cout<<" bhayya "<<it->first<<" "<<it->second<<endl;
		// }

		// cout<<bet<<" "<<cur<<" "<<k<<endl;
		if((bet-min(pts,cur))>=k)
			continue;

		int x=max(0,bet-k+1);

		if(x>pts)
			continue;

		// cout<<"unnanu\n";
		lli val=0;
		set<ii>::iterator it=s2.begin();
		for(int i=0;i<x;i++) {
			val+=(int)(it->first);
			s1.erase(*it);
			it++;
			// cout<<"s1 aya "<<it->first<<" "<<it->second<<endl;
		}

		it=s1.begin();
		for(int i=0;i<(pts-x);i++) {
			val+=(int)(it->first);
			it++;
			// cout<<"s1 "<<it->first<<" "<<it->second<<endl;
		}

		it=s2.begin();
		for(int i=0;i<x;i++) {
			s1.insert(*it);
			it++;
		}

		ans=min(ans,val);
		// cout<<"bro "<<x<<" "<<val<<" "<<ans<<endl;
	}

	if(ans==inf)
		printf("-1\n");
	else
		cout<<ans<<endl;
	return 0;
}
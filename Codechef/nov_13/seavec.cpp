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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,k,ans,ans1,num,A[1000000],sum,val,cur[1000000],val1,val2;
vector<lli> v[1000000],res,res1;
map<ii,int> m;
pair<ii,vector<lli> > p[10];
bool ok;

int main() {
	inp(t);

	for(int a=0;a<t;a++) {
		inp(n);
		inp(k);

		for(int i=0;i<n;i++) {
			v[i].clear();
			for(int j=0;j<k;j++) {
				inp(num);
				v[i].push_back(num);
			}
		}

		for(int i=0;i<k;i++)
			inp(A[i]);
		m.clear();
		for(int i=0;i<n;i++) {
			ok=false;
			val=0;
			for(int j=0;j<k;j++) {
				if(v[i][j]>A[j]) {
					ok=true;
					break;
				}
				val+=v[i][j];
			}
			if(ok)
				continue;
			m[ii(val,(lli)i)]=i;
		}

		val=0;

		for(int i=0;i<k;i++)
			val+=A[i];

		ans=0;
		res.clear();
		res1.clear();
		ans1=0;
		val1=0;
		val2=0;

		memset(cur,0,sizeof cur);

		int ind;
		for(map<ii,int>::iterator it=m.begin();it!=m.end();it++) {
			ind=it->second;

			for(int j=0;j<k;j++)
				cur[j]+=v[ind][j];
			
			ok=false;
			for(int j=0;j<k;j++) {
				if(cur[j]>A[j]) {
					ok=true;
					break;
				}
			}
			if(ok) {
				for(int j=0;j<k;j++)
					cur[j]-=v[ind][j];
			}
			else {
				val1+=(it->first).first;
				if((ans+1)>=(val-val1+1)) {
					val1-=(it->first).first;
					break;
				}
				ans++;
				res.push_back(ind+1);
			}
		}
		sort(res.begin(),res.end());

		memset(cur,0,sizeof cur);
		for(map<ii,int>::reverse_iterator it=m.rbegin();it!=m.rend();it++) {
			ind=it->second;
			for(int j=0;j<k;j++)
				cur[j]+=v[ind][j];
			
			ok=false;
			for(int j=0;j<k;j++) {
				if(cur[j]>A[j]) {
					ok=true;
					break;
				}
			}
			if(ok) {
				for(int j=0;j<k;j++)
					cur[j]-=v[ind][j];
			}
			else {
				val2+=(it->first).first;
				if((ans1+1)>=(val-val2+1)) {
					val2-=(it->first).first;
					break;
				}
				ans1++;
				res1.push_back(ind+1);
			}
		}
		sort(res1.begin(),res1.end());

		if(ans1*(val-val2+1)<ans*(val-val1+1)) {
			ans=ans1;
			res=res1;
			val1=val2;
		}

		p[a]=make_pair(ii(ans,val-val1+1),res);
		// ans=min(ans,(lli)10);
		// printf("%lld\n", ans);

		// for(int i=0;i<ans;i++)
		// 	printf("%lld ", res[i]);
		// printf("\n");
	}

	val=0;
	double f=0,big=0,ex,big1;
	set<pair<double,int> > s;
	for(int i=0;i<t;i++) {
		ex=(double)p[i].first.first/(double)p[i].first.second;
		f+=ex;
		s.insert(make_pair(ex,i));
	}

	big=s.rbegin()->first;
	set<pair<double,int> >::reverse_iterator it=s.rbegin(),it1;
	it1=it;
	it1++;

	while(it1!=s.rend()) {
		big=it->first;
		big1=it1->first;

		if((f/big)<(f-big)/big1) {
			p[it->second].first.first=0;
			f-=big;
			it++;
			it1++;
		}
		else
			break;
	}

	for(int i=0;i<t;i++) {
		printf("%lld\n", p[i].first.first);

		for(int j=0;j<p[i].first.first;j++) {
			printf("%lld ",(p[i].second)[j]);
		}
		printf("\n");
	}
	return 0;
}

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
#define ii pair<long long int,long long int>
#define mp make_pair
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

lli t,k,q,num,A[30000],B[30000],ans[200001],big;

set<pair<lli,ii> > s;
set<ii> s1;
int main() {
	inp(t);

	while(t--) {
		inp(k);
		inp(q);
		for(int a=0;a<k;a++)
			inp(A[a]);
		for(int a=0;a<k;a++)
			inp(B[a]);

		sort(A,A+k);
		sort(B,B+k);

		s.clear();
		s1.clear();

		lli ind=1;
		big=min((lli)10000,k*k);

		lli i=0,j=0,kri=0,a1,b1;

		for(int a=0;a<k;a++) {
			s.insert(mp(A[0]+B[a],ii(0,a)));
			s.insert(mp(A[a]+B[0],ii(a,0)));
		}
		// cout<<s.size()<<endl;
		a1=k;
		b1=k;

		set<pair<lli,ii> >::iterator it;

		while(ind<=big) {
			it=s.begin();
			ans[ind++]=it->first;
			s1.insert(it->second);
			// cout<<ind-1<<" "<<ans[ind-1]<<endl;
			// cout<<big<<endl;
			if((it->second).first==i) {
				a1--;
				// i++;
				if(a1==0 && (i+1)<k) {
					i++;

					// while(i<k) {
					for(int a=0;a<k;a++) {
						if(s1.find(ii(i,a))!=s1.end())
							continue;
						a1++;
						s.insert(mp(A[i]+B[a],ii(i,a)));
					}
						// if(a1)
						// 	break;
						// i++;
				}
				
			}
			if((it->second).second==j) {
				b1--;
				if(b1==0 && (j+1)<k) {
					j++;
					for(int a=0;a<k;a++) {
						if(s1.find(ii(a,j))!=s1.end())
							continue;
						b1++;
						s.insert(mp(A[a]+B[j],ii(a,j)));
					}					
				}
			}

			s.erase(s.begin());
		}

		while(q--) {
			inp(num);
			// if(num>big)
			// 	printf("0\n");
			printf("%lld\n", ans[num]);
		}
	}

	return 0;
}
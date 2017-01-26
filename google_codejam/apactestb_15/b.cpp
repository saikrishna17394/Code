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

lli t,a,b,c,m;
lli A[2001],B[2001],C[2001];

lli gcd(lli a,lli b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	// freopen("inp","r",stdin);
	// freopen("B-small-attempt1.in", "r", stdin);	
	freopen("B-large.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	for(lli z=1;z<=t;z++) {
		inp(a);
		inp(b);
		inp(c);

		for(lli i=0;i<a;i++)
			inp(A[i]);

		for(lli i=0;i<b;i++)
			inp(B[i]);

		for(lli i=0;i<c;i++)
			inp(C[i]);

		inp(m);
		set<ii> s;

		for(lli i=0;i<b;i++) {
			for(lli j=i+1;j<b;j++) {
				lli p=B[i],q=B[j];
				lli g=gcd(p,q);
				p/=g;
				q/=g;
				s.insert(ii(p,q));
				s.insert(ii(q,p));
				// cout<<p<<" "<<q<<endl;
			}
		}

		printf("Case #%lld:\n",z);
		while(m--) {
			lli p,q;
			inp(p);
			inp(q);

			bool ok=false;

			for(lli i=0;i<a;i++) {
				for(lli j=0;j<c;j++) {
					lli p1=p*C[j];
					lli q1=q*A[i];
					lli g=gcd(p1,q1);
					p1/=g;
					q1/=g;
					// cout<<p1<<" "<<q1<<endl;
					if(s.find(ii(p1,q1))!=s.end())
						ok=true;
				}
			}
			if(!ok)
				printf("No\n");
			else
				printf("Yes\n");
		}

	}



	return 0;
}
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

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli sum_dig(lli n) {
	lli val=0;

	while(n>0) {
		val+=n%10;
		n/=10;
	}

	return val;
}

vector<lli> v;
map<lli,int> m;

int solve(lli n) {
	if(m.find(n)!=m.end())
		return m[n];

	lli val=sum_dig(n);

	bool ok=false;
	for(lli i=2;i*i<=val;i++) {
		if(val%i==0)
			ok=true;
	}

	if(!ok) {
		m[n]=0;
		// cout<<n<<" ---ds "<<0<<endl;
		return 0;
	}

	
	int ret=0;
	for(int i=0;i<v.size();i++) {
		if(n%v[i]==0) 
			ret=ret|(solve(n/v[i])^1);
	}
	m[n]=ret;
	// cout<<n<<" --- "<<ret<<endl;
	return ret;
}



lli t,n;

int main() {
	// freopen("inp","r",stdin);
	// freopen("C-small-attempt0.in", "r", stdin);	
	freopen("C-large.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	for(lli z=1;z<=t;z++) {
		inp(n);

		if(n==1) {
			printf("Case #%lld: Seymour\n",z);
			continue;
		}

		lli num=n;
		v.clear();
		m.clear();
		m[1]=0;

		for(lli i=2;i*i<=n;i++) {
			if(num%i==0) {
				lli val=1;

				while(num%i==0) {
					num/=i;
					val*=i;
				}
				v.push_back(val);
			}
		}

		if(num==n) {
			// n is prime
			lli val=sum_dig(num);

			bool ok=false;
			for(lli i=2;i<val;i++) {
				if(val%i==0)
					ok=true;
			}

			if(ok)
				printf("Case #%lld: Laurence\n",z);
			else
				printf("Case #%lld: Seymour\n",z);
			continue;
		}

		if(num>1) {
			v.push_back(num);
		}

		int ans=solve(n);

		if(ans==1)
			printf("Case #%lld: Laurence\n",z);
		else
			printf("Case #%lld: Seymour\n",z);	
	}


	return 0;
}
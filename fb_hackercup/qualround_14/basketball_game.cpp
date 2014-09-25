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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


int main() {
	freopen("basketball_game.txt", "r", stdin);
	freopen("basketball_game_out.txt", "w", stdout);

	int t,p,n,m,tim[31],A[31],num;
	string name[31],s1,ans[31];
	ii p1;
	set<pair<ii,string> > s;
	inp(t);

	for(int a=1;a<=t;a++) {
		memset(tim,0,sizeof tim);
		memset(A,0,sizeof A);
		s.clear();
		
		inp(n);
		inp(m);
		inp(p);
		for(int i=0;i<n;i++) {
			cin>>s1;
			inp(p1.first);
			inp(p1.second);
			s.insert(mp(p1,s1));
		}

		int ind=1,ind1;
		for(set<pair<ii,string> >::reverse_iterator it=s.rbegin();it!=s.rend();it++,ind++)
			name[ind]=it->second;

		for(int i=1;i<=2*p;i++) {
			A[i]=1;
			tim[i]=1;
		}

		while(m--) {
			if(n>2*p) {
				num=-1;
				for(int i=1;i<=n;i+=2) { 
					if(A[i]==1 && tim[i]>=num) {
						num=tim[i];
						ind=i;
					}
				}
				num=10000;
				for(int i=1;i<=n;i+=2) { 
					if(A[i]==0 && tim[i]<num) {
						num=tim[i];
						ind1=i;
					}
				}
				A[ind]=0;
				A[ind1]=1;
			}
			if(n>(2*p+1)) {
				num=-1;
				for(int i=2;i<=n;i+=2) { 
					if(A[i]==1 && tim[i]>=num) {
						num=tim[i];
						ind=i;
					}
				}
				num=10000;
				for(int i=2;i<=n;i+=2) { 
					if(A[i]==0 && tim[i]<num) {
						num=tim[i];
						ind1=i;
					}
				}
				A[ind]=0;
				A[ind1]=1;
			}

			for(int i=1;i<=n;i++)
				if(A[i])
					tim[i]++;
		}

		ind=0;
		for(int i=1;i<=n;i++) {
			if(A[i]) {
				ans[ind++]=name[i];
			}
		}
		sort(ans,ans+ind);

		printf("Case #%d:",a);
		for(int i=0;i<ind;i++)
			cout<<" "<<ans[i];
		cout<<endl;
	}


	return 0;
}
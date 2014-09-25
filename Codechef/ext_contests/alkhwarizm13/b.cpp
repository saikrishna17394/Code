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
	int t,p,n[100],m[100],ans;	

	int sg[10001];
	inp(t);

	while(t--) {
		inp(p);
		ans=0;
		for(int i=0;i<p;i++) {
			inp(n[i]);
			inp(m[i]);

			if(m[i]>n[i]) {
				ans^=(n[i]%2);
				continue;
			}
			if(m[i]==n[i]) {
				if(n[i]%2==0)
					ans^=1;
				else
					ans^=2;
				continue;
			}
			sg[0]=0;
			vector<int> poss_moves;
			poss_moves.push_back(1);

			if(m[i]<=n[i]) {
				poss_moves.push_back(m[i]);
			
				int ind=1;

				while(poss_moves[ind]+poss_moves[ind-1]<=n[i]) {
					poss_moves.push_back(poss_moves[ind]+poss_moves[ind-1]);
					ind++;
				}
			}
			for(int k=0;k<poss_moves.size();k++)
				cout<<k<<" "<<poss_moves[k]<<endl;
			sg[0];

			for(int j=1;j<=n[i];j++) {
				set<int> s;
				int val=0;

				// cout<<poss_moves.size()<<endl;
				for(int k=0;k<poss_moves.size();k++) {
					// cout<<j<<" d "<<poss_moves[k]<<endl;
					if(poss_moves[k]>j)
						break;
					// cout<<
					// cout<<j<<" d "<<poss_moves[k]<<endl;
					// cout<<sg[j-poss_moves[k]]<<endl;
					s.insert(sg[j-poss_moves[k]]);
				}

				while(s.find(val)!=s.end())
					val++;

				sg[j]=val;
				// if(sg[j]==0)
				// 	cout<<j<<" "<<sg[j]<<endl;
			}
			// cout<<n[i]<<" "<<sg[n[i]]<<endl;
			// cout<<ans<<endl;
			ans^=sg[n[i]];
			// cout<<ans<<endl;
		}
		// cout<<ans<<endl;
		if(ans)
			printf("Jack\n");
		else
			printf("Angelica\n");
	}

	return 0;
}
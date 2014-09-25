#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <list>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int t,n,m,A[100001],k,num,ans=0,a,b,ind;

multiset<pair<int,int> > s[100001];

int main() {
	inp(n);
	inp(m);

	for(int i=1;i<=n;i++)
		inp(A[i]);

	for(int i=1;i<=m;i++) {
		inp(a);
		inp(b);
		s[a].insert(make_pair(b,b-a+1));
	}

	inp(t);

	while(t--) {
		inp(a);
		ind=ans+a;

		A[ind]--;
		if(A[ind]==0) {

			for(int i=1;i<=ind;i++) {
				list<pair<int,int> > l;
				for(set<pair<int,int> >::reverse_iterator it=s[i].rbegin();it!=s[i].rend();it++ ) {
					if((*it).first>=ind) {
						//cout<<ind<<" "<<i<<" "<<(*it).first<<endl;
						l.push_back(*it);

					}
					else
						break;
				}

				for(list<pair<int,int> >::iterator it=l.begin();it!=l.end();it++ ) {
					s[i].erase(*it);
					int kri=(*it).second;
					//cout<<ind<<" yo "<<i<<" "<<(*it).first<<" "<<kri<<endl;
					if(kri>1) {
						s[i].insert(make_pair((*it).first,kri-1));
					}
					else
						ans++;
				}

			}

		}

		printf("%d\n",ans);

	}

	return 0;
}
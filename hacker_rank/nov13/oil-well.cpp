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

int r,c,A[50][50];
int D[50][50],ans,val,i1,J1;

ii ver;
pair<int,ii> p;
set<pair<int,ii> >s;
vector<ii> v;

int dx[8]={+1,-1,0,0,+1,+1,-1,-1};
int dy[8]={0,0,+1,-1,+1,-1,+1,-1};


int main() {
	inp(r);
	inp(c);
	ans=inf;
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			inp(A[i][j]);
			if(A[i][j])
				v.push_back(ii(i,j));
		}
	}
	
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(A[i][j]) {
				memset(D,-1,sizeof D);

				s.clear();
				s.insert(make_pair(0,ii(i,j)));
				D[i][j]=0;
				val=0;
				while(!s.empty()) {
					p=*s.begin();
					s.erase(s.begin());
					ver=p.second;
					val+=D[ver.first][ver.second];
					D[ver.first][ver.second]=0;

					for(int a=0;a<v.size();a++) {
						int x=v[a].first,y=v[a].second;
						if(D[x][y]){
							if(D[x][y]<max(abs(x-ver.first),abs(y-ver.second) )) {
								if(D[x][y]!=-1)
									s.erase(s.find(make_pair(D[x][y],ii(x,y))));
								D[x][y]=max(abs(x-ver.first),abs(y-ver.second));
								s.insert(make_pair(D[x][y],ii(x,y)));
							}
						}
					}
				}
				ans=min(ans,val);
			}
		}
	}

	if(ans==inf)
		ans=0;
	printf("%d\n", ans);
	return 0;
}
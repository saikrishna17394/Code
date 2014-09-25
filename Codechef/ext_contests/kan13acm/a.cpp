#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 1e10
#define ii pair<int,int>
#define pii pair<double,pair<int,int> >
#define mp make_pair

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int t,r,c,q,x1,Y1,x2,y2,x,y;
double A[100][100],D[100][100];

int dx[]={-1,-1,+1,+1};
int dy[]={+1,-1,+1,-1};

bool check(int a,int b) {
	if(a<0 || a>=r || b<0 || b>=c)
		return false;
	return true;
}
double dist(int a,int b,int a1,int b1) {
	double h1=A[a][b],h2=A[a1][b1],aa=(h1-h2);
	aa*=aa;
	if(h1>h2) {
		return 0.5+0.5*sqrt(1+aa);
	}
	return -0.5+1.5*sqrt(1+aa);
}
int main() {
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	pii top;
	ii ver;
	double cost,val;

	inp(t);

	while(t--) {
		inp(r);
		inp(c);

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++) {
				cin>>A[i][j];
			}

		inp(q);

		while(q--) {
			inp(x1);
			inp(Y1);
			inp(x2);
			inp(y2);
			x1--;
			Y1--;
			y2--;
			x2--;

			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					D[i][j]=inf;
			D[x1][Y1]=0;
			while(!Q.empty())
				Q.pop();

			Q.push(mp(0,ii(x1,Y1)));
			D[x1][Y1]=0;

			while(!Q.empty()) {
				top=Q.top();
				Q.pop();

				ver=top.second;
				cost=top.first;
				if(ver.first==x2 && ver.second==y2) {
					cout<<cost<<endl;
					break;
				}

				if(cost<=D[ver.first][ver.second]) {

					for(int i=0;i<4;i++) {
						int a,b;
						a=ver.first+dx[i];
						b=ver.second+dy[i];
						// x=y=0;
						if(check(a,b)) {
							val=dist(ver.first,ver.second,a,b);

							if(D[a][b]>cost+val) {
								D[a][b]=cost+val;
								Q.push(make_pair(D[a][b],ii(a,b)));
							}
						}
					}

				}
			}

		}
	}



	return 0;
}
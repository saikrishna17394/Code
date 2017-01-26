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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,tree[1025][1025];
lli x2,y2,x1,Y1,num,ans;
char s[4];

void upd(lli x,lli y,lli val) {
	while(x<=n) {
		lli idx_y=y;
		while(idx_y<=n) {
			tree[x][idx_y]+=val;
			idx_y+=idx_y&-idx_y;
		}
		x+=x&-x;
	}
}

lli query(lli x,lli y) {
	lli sum=0;
	while(x>0) {
		lli idx=y;
		while(idx>0) {
			sum+=tree[x][idx];
			idx-=idx&-idx;
		}
		x-=x&-x;
	}
	return sum;
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(lli i=0;i<=n;i++)
			for(lli j=0;j<=n;j++)
				tree[i][j]=0;

		while(1) {
			scanf("%s",s);
			if(s[0]=='E') {
				printf("\n");
				break;
			}

			if(s[1]=='E') {
				inp(x1);
				inp(Y1);
				inp(num);
				
				x1++;Y1++;
				x2=x1;
				y2=Y1;

				ans=query(x2,y2);
				ans-=query(x1-1,y2);
				ans-=query(x2,Y1-1);
				ans+=query(x1-1,Y1-1);

				upd(x1,Y1,num-ans);
			}
			else {
				inp(x1);
				inp(Y1);
				inp(x2);
				inp(y2);
				x1++;x2++;Y1++;y2++;

				ans=query(x2,y2);
				ans-=query(x1-1,y2);
				ans-=query(x2,Y1-1);
				ans+=query(x1-1,Y1-1);

				printf("%lld\n", ans);
			}
		}
	}


	return 0;
}
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
#define ii pair<data,int>

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

int dp[8][8][8][8][8][8][3];

bool check(int x,int y,int x1,int Y1,int x2,int y2) {
	if(x<0 || x>7)
		return false;
	if(y<0 || y>7)
		return false;
	if(x==x1 && y==Y1)
		return false;
	if(x==x2 && y==y2)
		return false;
	return true;
}
struct data{
	int x1,Y1,x2,y2,x3,y3,ind;
	void fun(int a,int b,int c,int d,int e,int f,int g) {
		x1=a;
		Y1=b;
		x2=c;
		y2=d;
		x3=e;
		y3=f;
		ind=g;
	}
};

bool check1(data d) {
	if(dp[d.x1][d.Y1][d.x2][d.y2][d.x3][d.y3][d.ind]==1)
		return false;
	return true;
}
int t,x1,x2,x3,Y1,y2,y3;
bool ans(data d){
	if(d.x1==x3 && d.Y1==y3 && d.x2==x1 && d.y2==Y1 && d.x3==x2 && d.y3==y2)
		return true;
	return false;
}
void yo(data d) {
	dp[d.x1][d.Y1][d.x2][d.y2][d.x3][d.y3][d.ind]=1;
}


int main() {
	data d,d1;
	bool ok;
	queue<pair<data,int> > q;
	pair<data,int> p;
	inp(t);

	while(t--) {
		inp(x1);
		inp(Y1);
		inp(x2);
		inp(y2);
		inp(x3);
		inp(y3);

		memset(dp,0,sizeof dp);
		while(!q.empty())
			q.pop();

		d.fun(x1,Y1,x2,y2,x3,y3,0);
		q.push(ii(d,0));

		dp[d.x1][d.Y1][d.x2][d.y2][d.x3][d.y3][d.ind]=1;

		while(!q.empty()) {
			p=q.front();
			q.pop();
			d=p.first;
			dp[d.x1][d.Y1][d.x2][d.y2][d.x3][d.y3][d.ind]=1;
			d1=d;
			ok=false;

			if(d.ind==0) {
				d1.ind=1;
				d1.x1=d.x1+2;
				d1.Y1=d.Y1+1;
				if(check(d1.x1,d1.Y1,d.x2,d.y2,d.x3,d.y3) && check1(d1)) {
					yo(d1);if(ans(d1)) {
						printf("%d\n", p.second+1);
						break;
					}
					q.push(ii(d1,p.second+1));
				}
				d1.x1=d.x1-2;
				d1.Y1=d.Y1-1;
				if(check(d1.x1,d1.Y1,d.x2,d.y2,d.x3,d.y3) && check1(d1)) {
					yo(d1);if(ans(d1)) {
						printf("%d\n", p.second+1);
						break;
					}
					q.push(ii(d1,p.second+1));
				}
				d1.x1=d.x1+1;
				d1.Y1=d.Y1+2;
				if(check(d1.x1,d1.Y1,d.x2,d.y2,d.x3,d.y3) && check1(d1)) {
					yo(d1);if(ans(d1)) {
						printf("%d\n", p.second+1);
						break;
					}
					q.push(ii(d1,p.second+1));
				}
				d1.x1=d.x1-1;
				d1.Y1=d.Y1-2;
				if(check(d1.x1,d1.Y1,d.x2,d.y2,d.x3,d.y3) && check1(d1)) {
					yo(d1);if(ans(d1)) {
						printf("%d\n", p.second+1);
						break;
					}
					q.push(ii(d1,p.second+1));
				}

			}
			else if(d.ind==1) {
				d1.ind=2;
				for(int i=1;i<8;i++) {
					d1.x2=d.x2+i;
					d1.y2=d.y2;
					if(check(d1.x2,d1.y2,d.x1,d.Y1,d.x3,d.y3) && check1(d1)) {
						yo(d1);
						if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
					}
					else
						break;
				}
				if(ok)
					break;
				for(int i=1;i<8;i++) {
					d1.x2=d.x2-i;
					d1.y2=d.y2;
					if(check(d1.x2,d1.y2,d.x1,d.Y1,d.x3,d.y3) && check1(d1)) {
						yo(d1);if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
						
					}
					else
						break;
				}
				if(ok)
					break;
				for(int i=1;i<8;i++) {
					d1.x2=d.x2;
					d1.y2=d.y2+i;
					if(check(d1.x2,d1.y2,d.x1,d.Y1,d.x3,d.y3) && check1(d1)) {
						yo(d1);if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
						
					}
					else
						break;
				}
				if(ok)
					break;
				for(int i=1;i<8;i++) {
					d1.x2=d.x2;
					d1.y2=d.y2-i;
					if(check(d1.x2,d1.y2,d.x1,d.Y1,d.x3,d.y3) && check1(d1)) {
						yo(d1);if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
						
					}
					else
						break;
				}
				if(ok)
					break;

			}
			else {
				d1.ind=0;
				for(int i=1;i<8;i++) {
					d1.x3=d.x3+i;
					d1.y3=d.y3+i;
					if(check(d1.x3,d1.y3,d.x1,d.Y1,d.x2,d.y2) && check1(d1)) {
						yo(d1);if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
						
					}
					else
						break;
				}
				if(ok)
					break;
				for(int i=1;i<8;i++) {
					d1.x3=d.x3+i;
					d1.y3=d.y3-i;
					if(check(d1.x3,d1.y3,d.x1,d.Y1,d.x2,d.y2) && check1(d1)) {
						yo(d1);if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
						
					}
					else
						break;
				}
				if(ok)
					break;
				for(int i=1;i<8;i++) {
					d1.x3=d.x3-i;
					d1.y3=d.y3+i;
					if(check(d1.x3,d1.y3,d.x1,d.Y1,d.x2,d.y2) && check1(d1)) {
						yo(d1);if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
						
					}
					else
						break;
				}
				if(ok)
					break;
				for(int i=1;i<8;i++) {
					d1.x3=d.x3-i;
					d1.y3=d.y3-i;
					if(check(d1.x3,d1.y3,d.x1,d.Y1,d.x2,d.y2) && check1(d1)) {
						yo(d1);if(ans(d1)) {
							printf("%d\n", p.second+1);
							ok=true;
							break;
						}
							q.push(ii(d1,p.second+1));
						
					}
					else
						break;
				}
				if(ok)
					break;
			}
		}

	}

	return 0;
}
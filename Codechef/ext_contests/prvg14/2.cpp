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
int t,n,len;
lli num,val,num1,num2;
lli A[1500001],s,s1;
char ch;

pair<lli,ii> ver;
queue<pair<lli,ii> > q;
ii p;

lli check(lli n) {
	lli d=1;
	num=n;
	while(n) {
		// cout<<n<<endl;
		n/=10;
		d*=10;
	}
	d/=10;
	return num%d;
}
int main() {
	set<lli> s;
	q.push(make_pair(2,ii(2,0)));
	A[1]=2;
	q.push(make_pair(4,ii(4,0)));
	A[2]=4;
	q.push(make_pair(6,ii(6,0)));
	A[3]=6;
	q.push(make_pair(8,ii(8,0)));
	A[4]=8;

	for(lli i=0;i<10;i+=2)
		s.insert(i);

	int cnt=5;
	bool kri=false;

	while(!q.empty()) {
		ver=q.front();
		q.pop();

		for(int i=0;i<9;i+=2) {
			val=ver.first*10+i;

			p=ver.second;
			swap(p.first,p.second);
			p.first=(p.first+val%10)%11;

			if(p.first==p.second)
				continue;
			if(s.find(check(val))==s.end())
				continue;
			A[cnt++]=val;
			s.insert(val);
			// cout<<cnt-1<<" "<<A[cnt-1]<<endl;
			q.push(make_pair(val,p));
			// if(cnt==137) {
			if(cnt==1500001) {
				kri=true;
				break;
			}
		}
		if(kri)
			break;
	}

	// cout<<A[cnt-1]<<endl;
	inp(t);
	while(t--) {
		inp(n);
		printf("%lld\n", A[n]);
	}
	
	return 0;
}
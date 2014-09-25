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
#define ii pair<long long int,long long int>

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

lli gcd(lli a,lli b) {
	if(b==0)
		return a;
	
	return gcd(b,a%b);
}

ii add(ii p1,ii p2) {
	ii p;
	p.second=gcd(p1.second,p2.second);

	p1.first*=(p2.second/p.second);
	p2.first*=(p1.second/p.second);

	p.first=p1.first+p2.first;
	p.second*=(p2.second/p.second)*(p1.second/p.second);
	return p;
}

int main() {
	int t,k,n,num,odd,even;
	lli f1,f2,fin1,fin2;

	set<int> s;

	inp(t);

	while(t--) {
		inp(k);
		odd=even=0;

		fin1=0;
		fin2=1;

		for(int i=0;i<k;i++) {
			inp(n);
			s.clear();
			for(int i=0;i<n;i++) {
				inp(num);
				s.insert(num);
			}
			if(n==0)
				continue;
			num=*(s.begin());
			if(num&1) {
				f1=0;
				f2=1;
				set<int>::iterator it=s.begin();
				for(;it!=s.end();it++) {
					if((*it)&1)
						f1--;
					else
						break;
				}
				for(;it!=s.end();it++) {
					f1<<=1;
					f2<<=1;
					if((*it)&1)
						f1--;
					else
						f1++;
				}
			}
			else {
				f1=0;
				f2=1;
				set<int>::iterator it=s.begin();
				for(;it!=s.end();it++) {
					if((*it)&1)
						break;
					else
						f1++;
				}
				for(;it!=s.end();it++) {
					f1<<=1;
					f2<<=1;
					if((*it)&1)
						f1--;
					else
						f1++;
				}
			}
			// cout<<f1<<" "<<f2<<endl;
			ii p=add(ii(fin1,fin2),ii(f1,f2));
			fin1=p.first;
			fin2=p.second;
			// cout<<fin1<<" "<<fin2<<endl;
		}


		if(fin1==0)
			printf("DON'T PLAY\n");
		else if(fin1<1)
			printf("ODD\n");
		else
			printf("EVEN\n");
	}

	return 0;
}
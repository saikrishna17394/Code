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

int A[300001],cnt[300001][1000],k,n,mm,a,b,sqr,B[1000],big,num,val;

map<int,int> m,ind,m1;
int pos[1000];
set<int> s;

int main() {

	inp(n);
	inp(k);

	sqr=sqrt(n);
	num=0;


	for(int i=1;i<=n;i++) {
		inp(A[i]);
		m[A[i]]++;
		if(m[A[i]]>=sqr) {
			s.insert(A[i]);
		}
	}

	val=0;
	for(set<int>::iterator it=s.begin();it!=s.end();it++) {
		m[*it]=val++;
		pos[val-1]=*it;
	}

	for(int i=0;i<val;i++)
		cnt[0][i]=0;

	for(int i=1;i<=n;i++) {
		for(int j=0;j<val;j++)
			cnt[i][j]=cnt[i-1][j];
		if(m.find(A[i])!=m.end())
			cnt[i][m[A[i]]]++;
	}

	inp(mm);

	while(mm--) {
		inp(a);
		inp(b);
		big=0;
		num=b-a+1;
		num/=2;
		num++;

		if((b-a+1)<=2*sqr) {
			m1.clear();

			for(int i=a;i<=b;i++)
				m1[A[i]]++;

			
			bool ok=false;
			for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++) {
				if(it->second>=num) {
					printf("yes %d\n",it->first);
					ok=true;
					break;
				}
			}
			if(ok)
				continue;
			printf("no\n");
		}
		else {
			bool ok=false;
			for(int i=0;i<val;i++) {
				B[i]=cnt[a][i]-cnt[b-1][i];
				if(B[i]>=num) {
					printf("yes %d\n", pos[i]);
					ok=true;
					break;
				}
			}
			if(ok)
				continue;
			printf("no\n");
		}
	}
	return 0;
}
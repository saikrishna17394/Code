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
#include <iomanip>
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli n,k,A[100000];
ii ans;
map<lli,int> m;
lli a,d;

int main() {
	inp(n);
	inp(k);

	for(int i=0;i<n;i++)
		inp(A[i]);

	if(n<100) {
		ans.first=A[0];
		ans.second=A[1]-A[0];


		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if((A[j]-A[i])%(j-i)==0) {
					d=(A[j]-A[i])/(lli)(j-i);
					a=A[i]-(lli)i*d;

					lli cnt=0;
					for(int l=0;l<n;l++) {
						if((a+(lli)l*d)!=A[l])
							cnt++;
					}

					if(cnt<=k) {
						if(a<ans.first) {
							ans.first=a;
							ans.second=d;
						}
						else if(a==ans.first) {
							ans.second=min(d,ans.second);
						}
						else
							;
					}
				}
			}
		}
		a=ans.first;
		d=ans.second;
	}
	else {

		for(int i=1;i<n;i++)
			m[A[i]-A[i-1]]++;

		int num=0;
		for(map<lli,int>::iterator it=m.begin();it!=m.end();it++) {
			if(it->second>num) {
				num=it->second;
				d=it->first;
			}
		}

		m.clear();

		for(int i=0;i<n;i++) {
			m[A[i]-(lli)i*d]++;
		}

		num=0;
		for(map<lli,int>::iterator it=m.begin();it!=m.end();it++) {
			if(it->second>num) {
				num=it->second;
				a=it->first;
			}
		}

	}
	for(int i=0;i<n;i++)
		printf("%lld ",a+(lli)i*d );
	printf("\n");
	return 0;
}
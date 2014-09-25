#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {

	lli t,val=0,ans,A[1000];
	string s;
	cin>>t;
	while(t--) {
		cin>>s;

		lli k=s.length();

		set<char> se;
		for(int i=0;i<k;i++) {
			se.insert(s[i]);
		}

		lli sz=se.size();
		if(sz==1) {
			ans=1<<k;
			ans--;
			printf("%lld\n",ans);
			continue;
		}

		memset(A,-1,sizeof A);
		val=0;
		A[s[0]]=1;

		for(int i=1;i<k;i++) {
			//cout<<A[s[i]]<<" "<<endl;
			if(A[s[i]]==-1) {
				A[s[i]]=val;
				if(val>0)
					val++;
				else
					val=2;
			}
		}

		ans=0;
		lli base=1;
		for(int i=k-1;i>=0;i--) {
			ans+=A[s[i]]*base;
			base=base*sz;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
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
#define inf (lli)1e16

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

ii A[50],B[50];

int conv(string s) {
	int num=(s[0]-'0')*10+(s[1]-'0');
	int num1=(s[3]-'0')*10+(s[4]-'0');

	int ret=0;

	if(num>=8) {
		ret+=(num-8)*60+num1;
	}
	else {
		ret+=(num+4)*60+num1;
	}
	return ret;
}

int main() {
	int n,p;

	cin>>n>>p;


	for(int i=0;i<p;i++) {
		string s;
		string s1;

		cin>>s>>s1;

		A[i].second=conv(s);
		A[i].first=conv(s1);
		if(A[i].first==0)
			A[i].first=12*60;
	}

	sort(A,A+p);

	int ans=0;

	while(n--) {
		if(p==0)
			break;
		int idx=0;

		B[idx++]=A[0];

		vector<ii> v;

		for(int i=1;i<p;i++) {
			if(A[i].second>=B[idx-1].first) {
				B[idx++]=A[i];
			}
			else
				v.push_back(A[i]);
		}
		ans+=idx;

		p=v.size();

		for(int i=0;i<p;i++)
			A[i]=v[i];
	}
	cout<<ans<<endl;
	return 0;
}
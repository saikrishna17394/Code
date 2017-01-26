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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t;
string s;
vector<int> v[2];

int main() {
	inp(t);

	for(int a=1;a<=t;a++) {
		cin>>s;
		lli ans=0;
		v[0].clear();
		v[1].clear();

		map<int,int> m;
		m.clear();

		for(int i=0;i<s.length();i++) {
			if(s[i]=='0') {
				v[0].push_back(i);
				m[i]=0;
			}
			else {
				v[1].push_back(i);
				m[i]=1;
			}
		}

		int n=s.length();

		// cout<<"bro "<<s<<endl;
		for(int k=0;k<2;k++) {
			// cout<<k<<" :\n";
			for(int i=0;i<v[k].size();i++) {
				// cout<<v[k][i]<<" ";
				for(int j=i+1;j<v[k].size();j++) {

					int num=2*v[k][j]-v[k][i];
					// cout<<v[k][j]<<" a"<<num<<"\n";
					if(num>=n)
						break;
					if(m[num]==k)
						ans++;
				}
			}
			// printf("\n");
		}
		printf("Case %d: %lld\n", a,ans);
	}
	return 0;
}
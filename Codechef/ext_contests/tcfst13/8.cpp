#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
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

int main() {
	int h,m,n,ind1,ind2,num;
	string s,s1;

	map<string,int> m1;
	vector<string> v;
	inp(h);

	for(int j=1;j<=h;j++) {
		inp(m);
		inp(n);
		m1.clear();
		v.clear();

		cin>>s;

		m1[s]=0;
		v.push_back(s);

		for(int i=1;;i++) {
			if(s[0]=='+') {
				if(s[m-1]=='+')
					s[m-1]='-';
				else
					s[m-1]='+';
			}
			s1=s.substr(1);
			if(s[0]=='+')
				s1+='-';
			else
				s1+='+';

			if(m1.find(s1)==m1.end())
				m1[s1]=i;
			else {
				ind2=i;
				ind1=m1[s1];
				break;
			}
			s=s1;
			v.push_back(s);
		}
		printf("Experiment #%d:\n", j);
		while(n--) {
			inp(num);
			if(num<ind2)
				cout<<v[num]<<endl;
			else
				cout<<v[(num-ind1)%(ind2-ind1)+ind1]<<endl;
		}

	}

	return 0;
}
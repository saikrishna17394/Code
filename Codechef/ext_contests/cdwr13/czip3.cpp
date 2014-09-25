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
#define lim 10000001
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


bool check(string s) {
	int len=s.length();

	for(int i=1;i<len;i++)
		if(s[i-1]<s[i])
			return false;

	return true;
}

map<string,int> m;
queue<string> q;

// int find_ans(string s) {
// 	if(m.find(s)!=m.end())
// 		return m[s];
// 	cout<<s<<" "<<num1<<endl;
// 	num1++;
// 	cout<<s<<" "<<num1<<endl;
// 	if(check(s)) {
// 		m[s]=0;
// 		return 0;
// 	}
// 	m[s]=-1;
// 	if(k<2)
// 		return -1;


// 	for(int i=0;i<=(n-k);i++) {
// 		s1=s;

// 		for(int j=i,i1=(k+i-1);j<(k+i);j++,i1--)
// 			s1[j]=s[i1];

// 		val=find_ans(s1);

// 		if(val==-1)
// 			continue;
// 		else {
// 			if(m[s]==-1)
// 				m[s]=val+1;
// 			else
// 				m[s]=min(m[s],val+1);
// 		}
// 	}

// 	return m[s];

// }

int main() {
	int t,ans,depth,n,k;
	char ch;
	string s,s1,s2;

	inp(t);
	while(t--) {
		inp(n);
		inp(k);
		s="";
		for(int i=0;i<n;i++) {
			cin>>ch;
			s+=ch;
		}

		m.clear();
		while(!q.empty())
			q.pop();

		m[s]=0;
		q.push(s);
		
		ans=-1;

		while(!q.empty()) {
			s1=q.front();
			q.pop();

			depth=m[s1];
			if(check(s1)) {
				ans=depth;
				break;
			}

			for(int i=0;i<=(n-k);i++) {
				s2=s1;
				for(int j=i,i1=(k+i-1);j<(k+i);j++,i1--)
					s2[j]=s1[i1];

				if(m.find(s2)==m.end()) {
					q.push(s2);
					m[s2]=depth+1;
				}
			}
		}

		if(ans==-1)
			printf("NP\n");
		else
			printf("%d\n",ans);
	}

	return 0;
}
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
#define ii pair<string,int>

#define mod 1000000007
#define inf 1e9

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};

int vis[26][26][26];
string s,s1;


bool solve(string s) {
	if(vis[s[0]-'a'][s[1]-'a'][s[2]-'a']!=-1)
		return true;
	return false;
}

bool unvis(string s) {
	if(vis[s[0]-'a'][s[1]-'a'][s[2]-'a']==0) {
		vis[s[0]-'a'][s[1]-'a'][s[2]-'a']=1;
		return true;
	}
	return false;
}


int main() {
	cin>>s>>s1;
	int n;
	cin>>n;

	memset(vis,0,sizeof vis);
	while(n--) {
		string a,b,c;
		cin>>a>>b>>c;

		for(int i=0;i<a.length();i++)
			for(int j=0;j<b.length();j++)
				for(int k=0;k<c.length();k++)
					vis[a[i]-'a'][b[j]-'a'][c[k]-'a']=-1;
	}

	queue<ii> q;

	if(solve(s) && unvis(s))
		q.push(ii(s,0));

	while(!q.empty()) {
		ii ver=q.front();
		q.pop();

		if(ver.first==s1) {
			printf("%d\n", ver.second);
			return 0;
		}
	
		for(int a=0;a<6;a++) {
			string s2=ver.first;
			s2[0]=((s2[0]-'a'+dx[a]+26)%26)+'a';
			s2[1]=((s2[1]-'a'+dy[a]+26)%26)+'a';
			s2[2]=((s2[2]-'a'+dz[a]+26)%26)+'a';

			if(solve(s2) && unvis(s2))
				q.push(ii(s2,ver.second+1));
		}
	}

	printf("-1\n");

	return 0;
}
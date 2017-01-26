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

int dx[]={0,0,+1,+1,+1,-1,-1,-1};
int dy[]={+1,-1,0,+1,-1,0,+1,-1};

int r,c,vis[100][100];
int r_min,r_max,c_min,c_max;
string s[100];

vector<ii> v[500];
int cmp[500];

vector<string> A[26],s1;

int idx=0,cnt=0;

vector<string> rot(vector<string> a) {
	vector<string> b;
	b.resize(a[0].size());

	for(int i=0;i<b.size();i++) {
		b[i]="";
		for(int j=0;j<a.size();j++) {
			b[i]+=a[a.size()-j-1][i];
		}
	}
	return b;
}
bool check(vector<string> a,vector<string> b) {
	if(a.size()!=b.size() && a.size()!=b[0].size())
		return false;
	if(a[0].size()!=b.size() && a[0].size()!=b[0].size())
		return false;

	for(int k=0;k<4;k++) {
		if(a.size()==b.size() && a[0].size()==b[0].size()) {
			bool ok=true;
			for(int i=0;i<a.size();i++) {
				for(int j=0;j<a[0].size();j++) {
					if(a[i][j]!=b[i][j]) {
						ok=false;
						break;
					}
				}
				if(!ok)
					break;
			}
			if(ok)
				return true;

			ok=true;
			for(int i=0;i<a.size();i++) {
				for(int j=0;j<a[0].size();j++) {
					if(a[i][j]!=b[a.size()-i-1][j]) {
						ok=false;
						break;
					}
				}
				if(!ok)
					break;
			}
			if(ok)
				return true;
		}
		a=rot(a);
	}
	return false;
}


void dfs(int i,int j) {
	v[idx].push_back(ii(i,j));
	vis[i][j]=1;
	r_min=min(i,r_min);
	r_max=max(i,r_max);
	c_min=min(j,c_min);
	c_max=max(j,c_max);

	for(int a=0;a<8;a++) {
		int x=i+dx[a];
		int y=j+dy[a];
		if(x<0 || x>=r || j<0 || j>=c)
			continue;
		if(vis[x][y]==0 && s[x][y]=='1')
			dfs(x,y);
	}
}

int main() {
	inp(c);
	inp(r);

	for(int i=0;i<r;i++)
		cin>>s[i];

	memset(vis,0,sizeof vis);

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(vis[i][j]==0 && s[i][j]=='1') {
				
				r_min=i;
				r_max=i;
				c_min=j;
				c_max=j;

				dfs(i,j);
				// cout<<" fuck"<<v[idx].size()<<endl;
				s1.clear();
				// cout<<"who "<<i<<" "<<j<<endl;
				s1.resize(r_max-r_min+1);
				// cout<<"who "<<i<<" "<<j<<endl;
				for(int k=0;k<s1.size();k++) {
					s1[k]="";
					for(int l=0;l<(c_max-c_min+1);l++)
						s1[k]+='0';
				}

				for(int k=0;k<v[idx].size();k++) {
					s1[v[idx][k].first-r_min][v[idx][k].second-c_min]='1';
				}
				// cout<<"whaa "<<i<<" "<<j<<" "<<cnt<<endl;
				bool ok=true;
				for(int k=0;k<cnt;k++) {
					if(check(s1,A[k])) {
						cmp[idx]=k;
						ok=false;
						break;
					}
				}
				// cout<<"fukkkwhaa "<<i<<" "<<j<<endl;
				if(ok) {
					A[cnt]=s1;
					cmp[idx]=cnt++;

				}

				idx++;
				// cout<<"who "<<i<<" "<<j<<endl;
			}
		}
	}

	// cout<<"fuck "<<idx<<endl;
	for(int i=0;i<idx;i++) {
		// cout<<"man "<<v[i].size()<<endl;
		for(int j=0;j<v[i].size();j++) {
			// cout<<v[i][j].first<<" "<<v[i][j].second<<" "<<cmp<<endl;
			s[v[i][j].first][v[i][j].second]=cmp[i]+'a';
		}
	}

	for(int i=0;i<r;i++)
		cout<<s[i]<<endl;

	return 0;
}
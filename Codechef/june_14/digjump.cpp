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
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int n,A[10]={0};
string s;
vector<int> v[10];


queue<ii> q;
int vis[100000]={0};

int main() {
	// inp(n);
	cin>>s;
	n=s.length();

	for(int i=0;i<n;i++) {
		v[s[i]-'0'].push_back(i);
	}

	q.push(ii(0,0));

	vis[0]=1;

	while(!q.empty()) {
		ii top=q.front();
		q.pop();

		if(top.first==n-1) {
			printf("%d\n", top.second);
			break;
		}

		int ind=s[top.first]-'0';
		if(A[ind]==0) {
			A[ind]=1;

			for(int j=0;j<v[ind].size();j++) {
				if(vis[v[ind][j]]==0) {
					vis[v[ind][j]]=1;
					q.push(ii(v[ind][j],top.second+1));
				}

			}
		}

		if(top.first>0 && vis[top.first-1]==0) {
			vis[top.first-1]=1;
			q.push(ii(top.first-1,top.second+1));
		}

		if(top.first<(n-1) && vis[top.first+1]==0) {
			vis[top.first+1]=1;
			q.push(ii(top.first+1,top.second+1));		
		}
	}




	return 0;
}
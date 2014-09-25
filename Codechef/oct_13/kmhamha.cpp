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
vector<int> g[1000];
int t,n,a,b,ans,cnt,num,vis[1000],match[1000];
ii A[1000];

bool dfs(int i) {

    for(int j=0;j<g[i].size();j++) {
        if(vis[g[i][j]])
            continue;
        vis[g[i][j]]=1;
        if(match[g[i][j]]==-1 || dfs(match[g[i][j]])) {
            match[g[i][j]]=i;
            return true;
        }
    }
    return false;
}
int main() {
    map<int,int> m,m1;
    inp(t);
     
    while(t--) {
        inp(cnt);
        m.clear();
        m1.clear();
        
        for(int i=0;i<cnt;i++) {
            inp(a);
            inp(b);
            m[a]=1;
            m1[b]=1;
            A[i]=ii(a,b);
        }
        int val=0;
        for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
            g[val].clear();
            it->second=val++;
        }
        n=val;
        val=0;
        for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++) {
            it->second=val++;
        }

        for(int i=0;i<cnt;i++)
            g[m[A[i].first]].push_back(m1[A[i].second]);
        
        ans=0;
        memset(match,-1,sizeof match);
        for(int i=0;i<n;i++) {
            memset(vis,0,sizeof vis);
            if(dfs(i))
                ans++;
        }

        printf("%d\n", ans);
     
    }
    return 0;
} 
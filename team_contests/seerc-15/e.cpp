#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define fore(i, l, r) for(int i = l; i < r; i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<int, pii> pipii;
typedef vector<vi> vvi;
typedef long long int lli;

const int N = 20005;
vvi G(N), W(N);
lli D[16][16];
int emps[N],k;
lli dp[1<<15],bfee;

lli solve(vector<int> v) {
  lli ret;
  bool ok=false;
  do {
    lli val=D[0][v[0]+1];

    for(int i=1;i<v.size();i++) {
      val+=D[v[i-1]+1][v[i]+1];
    }

    if(!ok) {
      ret=val;
      ok=true;
    }
    else
      ret=min(ret,val);

  } while(next_permutation(v.begin(),v.end()));

  return ret;
}

lli fun(int mask) {
  lli& ret=dp[mask];
  if(ret!=-1)
    return ret;

  for(int i=0;i<k;i++) {
    if((mask&(1<<i))==0) {
      continue;
    }
    ret=D[0][i+1]+bfee+fun(mask^(1<<i));

    mask^=(1<<i);
    vector<int> v;
    v.push_back(i);

    for(int a=i+1;a<k;a++) {
      if((mask&(1<<a))==0)
        continue;

      v.push_back(a);
      ret=min(ret,bfee+ solve(v)+fun(mask^(1<<a)));
      mask^=(1<<a);

      for(int b=a+1;b<k;b++) {
        if((mask&(1<<b))==0)
          continue;

        v.push_back(b);
        ret=min(ret,bfee+solve(v)+fun(mask^(1<<b)));
        mask^=(1<<b);

        for(int c=b+1;c<k;c++) {
          if((mask&(1<<c))==0)
            continue;

          v.push_back(c);
          ret=min(ret,bfee+solve(v)+fun(mask^(1<<c)));
          v.pop_back();
        }

        mask^=(1<<b);
        v.pop_back();

      }
      mask^=(1<<a);
      v.pop_back();
    }

    break;
  }

  return ret;
}

set<int> s;

void dikshtra(int root, int n){
  int V[n];
  forn(i, n) V[i] = INF;
  set<pii> S;
  V[root] = 0;
  S.insert(mp(0, root));
  forn(i, n) if (i != root) S.insert(mp(INF, i));
  set<pii>::iterator it;
  while (!S.empty()){
    it = S.begin();
    int d = it->x, idx = it->y;
    
    if (s.find(idx)!=s.end()){
      for(int i=0;i<=k;i++) {
        if(emps[i]!=root)
          continue;
        for(int j=0;j<=k;j++) {
          if(emps[j]!=idx)
            continue;
          D[i][j]=d;
        }
      }
    } 

    S.erase(it);
    int l = G[idx].size();
    forn(i, l){
      int next = G[idx][i], w = W[idx][i];
      if (d + w < V[next]){
      	S.erase(mp(V[next], next));
      	V[next] = d + w;
      	S.insert(mp(V[next], next));
      }
    }
  } 
}


int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b, c, d;
  forn(i, m){
    scanf("%d %d %d %d", &a, &b, &c, &d);
    b--, c--;
    if (a == 1){
      G[b].pb(c);
      W[b].pb(d);
    }
    else {
      G[b].pb(c);
      W[b].pb(d);
      G[c].pb(b);
      W[c].pb(d);
    }
  }
  
  int cvertex;
  forn(i, n) emps[i] = -1;
  cin>>bfee>>cvertex;
  cvertex--;
  emps[0] = cvertex;
  scanf("%d", &k);

  s.insert(cvertex);

  forn(i, k){
    scanf("%d", &a);
    a--;
    emps[i+1] = a;
    s.insert(a);
  }

  for(set<int>::iterator it=s.begin();it!=s.end();it++)
    dikshtra(*it,n);

  memset(dp,-1,sizeof dp);
  dp[0]=0;

  printf("%lld\n", fun( (1<<k)-1 ) );
  // distances stored in D(u, v) = d, cvertex -> office = 0, bfee -> boarding fee, k -> number of employee
  
}

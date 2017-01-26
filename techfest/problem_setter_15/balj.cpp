//Coder: Balajiganapathi
#define TRACE
#define DEBUG
 
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
 
// Basic macros
#define st first
#define se second
#define all(x) (x).begin(), (x).end()
#define ini(a, v) memset(a, v, sizeof(a))
#define re(i,s,n) for(int i=s;i<(n);++i)
#define rep(i,s,n) for(int i=s;i<=(n);++i)
#define fr(i,n) re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t) repv(i,f - 1,t)
#define frv(i,n) rev(i,n,0)
#define pu push_back
#define mp make_pair
#define sz(x) (int)(x.size())
 
const int oo = 2000000009;
const double eps = 1e-9;
 
#ifdef TRACE
#define trace1(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 
#else
 
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
 
#endif
 
const int mx = 1000006;
const ll LIMIT = 1000000000012L;
map<ll, int> cnt;
vector<ll> v;
 
 
int get(ll x) {
return upper_bound(all(v), x ) - v.begin();
}
 
int main() {
int q;
ll a, b;
for(int base = 3; base < mx; ++base) {
ll b = 1, sum = 1;
for(; sum < LIMIT; ) {
//if(base == 3 || base == 12) trace3(base, b, sum);
++cnt[sum];
if(b >= LIMIT / base) break;
b *= base;
//if(base == 3 || base == 12) trace3(base, b, sum);
if(sum >= LIMIT - b) break;
sum += b;
}
}
 
for(map<ll, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
if(it->se >= 2) {
//if(it->st < 100) trace1(2 * it->st);
v.pu(2ll * it->st);
}
}

cout<<v.size()<<endl;
//trace1(sz(v));
//return 0;
 
scanf("%d", &q);
while(q--) {
scanf("%lld %lld", &a, &b);
printf("%d\n", get(b) - get(a - 1));
}
return 0;
}
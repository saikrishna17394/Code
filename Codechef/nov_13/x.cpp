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
#define lli long long int
#define ii pair<long long int,long long int>
 
#define mod 1000000007
#define inf 999999999
 
using namespace std;
 
inline void inp(lli &n ) {//fast input function
    n=0;
    lli ch=getchar_unlocked(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while( ch >= '0' && ch <= '9' )
    n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
    n=n*sign;
}
lli t,n,k,num,ans;
vector<lli> v[1000000],A,v1,res;
 
bool check() {
    for(int i=0;i<k;i++)
        if(v1[i]>A[i])
            return false;
    return true;
}
int main() {
 
    inp(t);
     
    while (t--) {
        inp(n);
        inp(k);
        for(int i=0;i<n;i++) {
            v[i].clear();
            for(int j=0;j<k;j++) {
                inp(num);
                v[i].push_back(num);
            }
            v[i].push_back(i+1);
        }
        A.clear();
        for(int i=0;i<k;i++) {
            inp(num);
            A.push_back(num);
        }
         
        ans=0;
        v1.clear();
         
        for(int i=0;i<k;i++)
            v1.push_back(0);
        res.clear();
         
        bool ok;
         
        for(int i=0;i<n;i++) {
            ok=false;
             
            // for(int j=0;j<k;j++)
            //     if(v[i][j]>A[j]) {
            //         ok=true;
            //      break;
            //     }
             
                 // if(ok)
                 //     continue;
            for(int j=0;j<k;j++) {
                v1[j]+=v[i][j];
            }
            if(check()) {
                res.push_back(v[i][k]);
                ans++;
            }
            else {
                for(int j=0;j<k;j++)
                    v1[j]-=v[i][j];
            }
        }
        sort(res.begin(),res.end());
        printf("%lld\n", ans);
        for(int i=0;i<ans;i++)
            printf("%lld ", res[i]);
        printf("\n");
    }
     
    return 0;
} 
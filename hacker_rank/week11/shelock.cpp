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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16
#define lim 1000001

using namespace std;

lli pow1(lli n,lli k) {
    lli ret=1;
    while(k>0) {
        if(k%2==1)
            ret=(ret*n)%mod;
        n=(n*n)%mod;
        k/=2;
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    lli t;
    lli n;
    cin>>t;
    while(t--) {
        cin>>n;
        lli ans=pow1(2,n);
        ans--;
        if(ans<mod)
            ans+=mod;
        ans=(ans*2)%mod;
        ans=(ans+4)%mod;
        cout<<ans<<endl;
    }
    return 0;
}

#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define xa getchar_unlocked()
#define lli unsigned long long int

inline void inp(lli &n ) {//fast input function
    n=0;
    lli ch=xa,sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=xa;}
    while( ch >= '0' && ch <= '9' )
    n=(n<<3)+(n<<1)+ ch-'0', ch=xa;
    n=n*sign;
}

lli prime[]={2, 3, 5, 7, 11, 13, 17,19,23};
lli mulmod(lli a,lli b,lli c){
    lli x = 0,y=a%c;
    while(b > 0){
    if(b%2 == 1){
    x = (x+y)%c;
    }
    y = (y*2)%c;
    b /= 2;
    }
 
return x%c;
}
lli modulo(lli a,lli b,lli c){
    lli x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
    if(b&1 == 1){
    x=mulmod(x,y,c);
    }
    y = mulmod(y,y,c); // squaring the base
    b /= 2;
    }
return x%c;
}
 
bool check_prime(lli p){
    if(p!=2 && (p&1)==0){
        return false;
    }
    lli s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<9 && prime[i]<p;i++){
        lli a=prime[i],temp=s;
        lli mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && (temp&1)==0){
            return false;
        }
    }
    return true;
}
 
int main() {
    lli ans=0;
    

    for(lli i=2;i<=50000000;i++) {
        cout<<i<<endl;
        if(check_prime(2*i*i-1))
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}

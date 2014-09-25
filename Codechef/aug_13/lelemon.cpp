#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define x getchar_unlocked()
using namespace std;
 
inline void inp(int &n ) {//fast input function
    n=0;
    int ch=x,sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=x;
    n=n*sign;
}
 
int main() {
    int A[100][100],C[100],ans,t,n,m,M[10000];
     
    inp(t);
    while(t--) {
        ans=0;
        inp(n);
        inp(m);
        for(int i=0;i<m;i++)
            inp(M[i]);
        for(int i=0;i<n;i++) {
            inp(C[i]);
            for(int j=0;j<C[i];j++)
                inp(A[i][j]);
            sort(A[i],A[i]+C[i]);
        }
         
        for(int i=0;i<m;i++) {
            if(C[M[i]]>0) {
                ans+=A[M[i]][C[M[i]]-1];
                C[M[i]]--;
            }
        }
         
        printf("%d\n",ans);
    }
     
    return 0;
} 
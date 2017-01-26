#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;

lli A[100000],n,l,r;

int main() {

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    l=1;
    r=(lli)1e6;
    //cout<<l<<" "<<r<<endl;
    while(l<r) {
        lli m=(l+r)/2;
        
        bool ok=true;
        lli e=m;
        for(int i=0;i<n;i++) {
            if(e>(lli)1e6) {
                break;
            }
            if(A[i]>e)
                e-=(A[i]-e);
            else
                e+=(e-A[i]);
            if(e<0) {
                ok=false;
                break;
            }
        }
        if(!ok)
            l=m+1;
        else
            r=m;
    }
    cout<<l<<endl;
    return 0;
}

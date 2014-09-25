#include <iostream>
#include <cstdio>
double d[10000001],b=3;int main(){d[1]=1;int a=-1,t,n,i;for(i=2;i<10000001;i++) {d[i]=d[i-1]+a*(1/b);a*=-1;b+=2;}std::cin>>t;while(t--){std::cin>>n;printf("%.16f\n", d[n]);}return 0;}

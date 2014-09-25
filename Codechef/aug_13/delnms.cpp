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
    int A[100001],B[100001]={0},big=0,n,cnt=0,num=1,C[100001][2],D[100001];
    inp(n);

    for(int i=1;i<=n;i++) {
        inp(A[i]);
        B[A[i]]++;
    }

    for(int i=1;i<=100000;i++) {
        if(B[i]>big) {
            big=B[i];
            num=i;
        }
    }

    /*for(int i=1;i<=100000;i++) {
        //if(i!=num) {
            cnt+=(B[i]+1)/2;
        //}
    }*/
    //cnt++;

    //printf("%d\n",cnt);

    int idx=n,val=1,siz=n;
    int ind=1;
    for(int i=n;i>0;i--) {
        if(B[A[i]]==1) {
            C[cnt][0]=i;C[cnt][1]=siz;
            cnt++;
            //B[A[idx]]--;
            siz--;            
        }
    }

    for(int i=1;i<=n;i++) {
        if(B[A[i]]>1)
            D[ind++]=A[i];
    }

    idx=ind-1;
    //cout<<idx<<endl;
    while(idx>0) {
      //  if(A[idx]!=num) {
        if(B[D[idx]]==siz) {
            C[cnt][0]=1;C[cnt][1]=1;
            cnt++;
            break;

        }
        if(B[D[idx]]==1) {
            //printf("%d %d\n",idx,siz);
            C[cnt][0]=idx;C[cnt][1]=siz;
            cnt++;
            B[D[idx]]--;
            siz--;
        }
        else {
            int i;
            for(i=idx-1;i>0;i--) {
                if(D[i]==D[idx])
                    break;
            }
            if(idx-i < 55000) {
                B[D[idx]]-=2;
                //printf("%d %d\n",i,idx-i);
                C[cnt][0]=i;C[cnt][1]=idx-i;
                cnt++;
            
                for(;i<idx;i++)
                    swap(D[i],D[i+1]);
                siz-=2;
                idx--;
            }
            else {
                B[D[idx]]-=1;
                //printf("%d %d\n",idx,siz);
                C[cnt][0]=idx;C[cnt][1]=siz;
                cnt++;
            
                siz--;
            }
        }
    //}
       // else
         //   ;
        idx--;
    }

    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d %d\n",C[i][0],C[i][1]);   
    //printf("1 1\n");
    return 0;
}
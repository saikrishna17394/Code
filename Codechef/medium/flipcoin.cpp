#include <iostream>
#include <math.h>
#include <stdio.h>
#include <bitset>
#define x getchar_unlocked()
#define y putchar_unlocked
#define max 1<<18
#define mod 1000000007
using namespace std;
inline void inp( int &n ) {//fast input function
    n=0;
    int ch=x,sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
    while( ch >= '0' && ch <= '9' )
    n=(n<<3)+(n<<1)+ ch-'0', ch=x;
    n=n*sign;
}
    int n,q,l,r,A[100000],op,ans,tree[max]={0},lazy[max]={0};
     
    void update_tree(int node,int a,int b,int i,int j) {
    //cout<<a<<" "<<b<<"yo\n";
    if(lazy[node]!=0) {
    lazy[node]%=2;
    if(lazy[node]==1) {
    tree[node]=(b-a+1)-tree[node];
    if(a!=b) {
    lazy[node*2]++;
    lazy[node*2+1]++;
    }
    }
    lazy[node]=0;
    }
    if(a>j || b<i)
    return;
    //cout<<"man\n";
    if(a>=i && b<=j) {
    tree[node]=(b-a+1)-tree[node];
    //cout<<tree[node]<<" "<<node<<"yea\n";
    if(a!=b) {
    lazy[node*2]++;
    lazy[node*2+1]++;
    }
    return;
    }
     
    update_tree(2*node,a,(a+b)/2,i,j);
    update_tree(2*node+1,(a+b)/2+1,b,i,j);
    tree[node]=tree[node*2]+tree[node*2+1];
    }
     
    int query(int node,int a,int b,int i,int j) {
    if(a>j || b<i)
    return 0;
    if(lazy[node]!=0) {
    lazy[node]%=2;
    if(lazy[node]==1) {
    tree[node]=(b-a+1)-tree[node];
    if(a!=b) {
    lazy[node*2]++;
    lazy[node*2+1]++;
    }
    }
    lazy[node]=0;
    }
    if(a>=i && b<=j)
    return tree[node];
    int ans1=query(node*2,a,(a+b)/2,i,j);
    int ans2=query(node*2+1,1+(a+b)/2,b,i,j);
    return ans1+ans2;
    }
     
    int main() {
    inp(n);
    inp(q);
    while(q--) {
    inp(op);
    inp(l);
    inp(r);
    if(op==0)
    update_tree(1,0,n-1,l,r);
    else
    printf("%d\n",query(1,0,n-1,l,r));
    /*for(int i=1;i<=8;i++)
    cout<<tree[i]<<" ";
    cout<<endl;
    for(int i=1;i<=8;i++)
    cout<<lazy[i]<<" ";
    cout<<endl;*/
     
    }
    return 0;
    }

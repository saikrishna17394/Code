#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cstdio>
using namespace std;

#define x getchar_unlocked()
#define MAXN 100010
#define MAXLG 19
#define mod 1000000009
inline void inp( int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}


char A[MAXN];

struct entry { 
    int nr[2], p;
} L[MAXN]; 

int P[MAXLG][MAXN], N, i, stp, cnt,H; 

int cmp(struct entry a, struct entry b) 
{ 
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0); 
}

void build() {
	H=0;
	//cout<<"0 :\n";
	for ( i = 0; i < N; i ++) {
	        P[0][i] = A[i] ;
	        //cout<<P[0][i]<<" ";
	    }
	//cout<<endl;


	//sort(L,L+N,cmp);

	    for (H=1,stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
	    { 
	        for (i = 0; i < N; i ++) 
	        { 
	            L[i].nr[0] = P[stp - 1][i]; 
	            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1; 
	            L[i].p = i;
	        } 
	        sort(L, L + N, cmp); 
	        for (i = 0; i < N; i ++) 
	            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
	        //cout<<cnt<<" :\n";
	        //for(i=0;i<N;i++)
	        //	cout<<P[stp][i]<<" ";
	        //cout<<endl;
	    }
	}

int lcp(int a, int b)  { 
    int k, ret = 0; 
    if (a == b) return N - a;
    for (k = stp - 1; k >= 0 && a < N && b < N; k --) 
        if (P[k][a] == P[k][b]) 
            a += 1 << k, b += 1 << k, ret += 1 << k; 
    return ret; 
}

pair<int,int> C[100010];
int t,n,B[100010];

int main() 
{ 
    inp(t);

    while(t--) {
    	inp(n);
    	for( i=0;i<n;i++)
    		inp(B[i]);
    	N=n-1;

    	for(i=0;i<N;i++) {
    		A[i]=B[i+1]-B[i]+100;
    		int c=A[i];
    		//cout<<c<<" ";
    	}
    	//cout<<endl;
    	build();
    	long long int ans=N;
    	ans=ans*(ans+1)/2;
    	//cout<<ans<<endl;
    	//cout<<cnt<<"  "<<stp<<endl;
    	for(i=0;i<N;i++) {
    		C[i]=make_pair(P[stp-1][i],i);
    		//cout<<P[stp-1][i]<<" ";
    	}

    	sort(C,C+N);
    	//cout<<endl;
    	for(i=1;i<N;i++)
    		ans-=(long long int)lcp(C[i].second,C[i-1].second);
    	//if(n==1)
    	//	cout<<n<<endl;
    	long long int val=mod;
    	ans=ans%mod;
    	//cout<<val<<endl;
    	printf("%lld\n",ans);
    }
     
    return 0;
}
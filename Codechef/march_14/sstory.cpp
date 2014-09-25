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
#define ii pair<int,int>

#define mod 1000000009
#define inf 999999999
#define MAXN 600010
#define MAXLG 23

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

string A;

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

    for (H=1,stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1) { 
        for (i = 0; i < N; i ++) { 
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

pair<int,int> C[MAXN];

int main() {
	string s;
	cin>>A;
	
	int len1=A.length();

	A+='#';
	cin>>s;
	A+=s;
	N=A.length();
	// cout<<A<<" "<<N<<endl;
	build();

	for(i=0;i<N;i++) {
	    C[i]=make_pair(P[stp-1][i],i);
	    //cout<<P[stp-1][i]<<" ";
	}

	sort(C,C+N);

	int ans=0,idx=inf;

	for(int i=1;i<N;i++) {
		if((C[i].second<len1 && C[i-1].second>len1) || (C[i].second>len1 && C[i-1].second<len1)) {
		    int num=lcp(C[i].second,C[i-1].second);
		    if(num==0)
		    	continue;
		    if(num>ans) {
		    	ans=num;
		    	idx=max(C[i].second,C[i-1].second);
		    }
		    else if(num==ans) {
		    	idx=min(idx,max(C[i].second,C[i-1].second));
		    }
		    else
		    	;
	    }
	}

	if(ans==0)
		printf("0\n");
	else {
		for(int i=0;i<ans;i++)
			printf("%c",A[idx+i] );
		printf("\n");
		printf("%d\n", ans);
	}
	return 0;
}
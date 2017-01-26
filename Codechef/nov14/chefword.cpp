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
#define vvd vector<vector<double> >

#define mod 1008
#define inf 999999999
#define lim 1000000
using namespace std;
 
inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar_unlocked(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while( ch >= '0' && ch <= '9' )
    n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

vvd mul(vvd A,vvd B) {
    vvd ret(26);
    for(int i=0;i<26;i++) {
        ret[i].resize(26);
        for(int j=0;j<26;j++)
            ret[i][j]=0;
    }

    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                ret[i][j]+=A[i][k]*B[k][j];
    return ret;
}

vvd power(vvd A,int k) {
    vvd ret(26);
    for(int i=0;i<26;i++) {
        ret[i].resize(26);
        for(int j=0;j<26;j++)
            ret[i][j]=0;
        ret[i][i]=1;
    }

    while(k>0) {
        if(k%2==1)
            ret=mul(ret,A);
        A=mul(A,A);
        k/=2;
    }
    return ret;
}

vvd A;
int t,n,k;

int main() {
    inp(t);
    A.resize(26);
    string s,s1;
    for(int i=0;i<26;i++)
        A[i].resize(26);

    while(t--) {
        inp(n);
        inp(k);
        cin>>s;
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                cin>>A[i][j];

        A=power(A,k);

        double ans=0;
        map<string,int> m;
        for(int i=0;i<n;i++) {
            cin>>s1;
            if(s.length()!=s1.length())
                continue;
            if(m.find(s1)!=m.end())
                continue;
            m[s1]=1;
            // cout<<s<<" "<<s1<<endl;
            double val=1;
            for(int i=0;i<s.length();i++) {
                val*=A[s[i]-'a'][s1[i]-'a'];
            }
            ans+=val;
        }
        printf("%.6f\n", ans);
    }
     
    return 0;
} 
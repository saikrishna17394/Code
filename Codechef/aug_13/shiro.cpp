#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#include <set>
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

double d[10001][100],a,b,ans;
int t,n,A[100],P[100],sum;

int main() {

	inp(t);

	while(t--) {
		inp(n);
		sum=0;

		for(int i=0;i<n;i++) {
			inp(A[i]);
			sum+=A[i];
		}

		for(int i=0;i<n;i++)
			inp(P[i]);

		
		memset(d,0,sizeof d);
		d[A[0]][0]=(double)P[0]/100.0;
		d[0][0]=(double)(100-P[0])/100.0;

		//cout<<d[0][0]<<" "<<d[A[0]][0]<<endl;


		for(int i=1;i<n;i++) {
			a=(double)(P[i])/100.0;
			b=1.0-a;

			for(int j=0;j<=100*i;j++) {
				d[A[i]+j][i]+=d[j][i-1]*a;
				d[j][i]+=d[j][i-1]*b;
			}
		}

		ans=0;
		for(int i=(sum+1)/2;i<=sum;i++)
			ans+=d[i][n-1];

		/*int k=(sum)/2;
		for(int i=0;i<=k;i++)
			ans+=d[i][n-1];*/

		//ans=1.0-ans;
		printf("%.7f\n",ans);
		

	}


	return 0;
}
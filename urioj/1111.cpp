#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int n,p,num;
int A[100][100];

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int main() {
	while(1) {
		cin>>n;
		if(n==0)
			break;
		for(int i=0;i<n*n;i++)
			for(int j=0;j<n*n;j++)
				A[i][j]=inf;

		for(int i=n-1;i>=0;i--) {
			for(int j=0;j<n;j++) {
				A[n*i+j][n*i+j]=0;
				for(int k=0;k<4;k++) {
					int x=i+dx[k],y=j+dy[k];
					cin>>num;
					if(num==1)
						A[n*i+j][n*x+y]=1;
				}
			}
		}

		for(int k=0;k<n*n;k++)
			for(int i=0;i<n*n;i++)
				for(int j=0;j<n*n;j++)
					A[i][j]=min(A[i][j],A[i][k]+A[k][j]);

		for(int i=0;i<n*n;i++) {
			for(int j=0;j<n*n;j++) {
				if(A[i][j]==inf)
					printf("9 ");
				else
					cout<<A[i][j]<<" ";
			}
			printf("\n");
		}


		cin>>p;
		int a,b,c,d;
		while(p--) {
			cin>>a>>b>>c>>d;
			int val=A[a*n+b][c*n+d];
			// val=min(val,A[c*n+d][a*n+b]);
			if(val==inf)
				printf("Impossible\n");
			else
				printf("%d\n", val);
		}

		printf("\n");
	}


	return 0;
}
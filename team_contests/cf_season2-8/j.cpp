#include <bits/stdc++.h>
#define inf 999999999
#define ii pair<int,int>

using namespace std;

int t;
string s;

int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

int A[1000][1000];
ii B[10000000];

int main() {
	cin>>t;
	
	cout<<t<<endl;
	
	while(t--) {
		cin>>s;
		
		int x=0,y=0;
		int dir=0;
		
		int x0=0,y0=0;
		
		memset(A,0,sizeof A);

		int a=0,b=0;		
		for(int i=0;i<s.length();i++) {
			if(s[i]=='B')
				dir+=2;
			else if(s[i]=='R')
				dir++;
			else if(s[i]=='L')
				dir+=3;
			else
				;
			dir%=4;
				
			x+=dx[dir];
			y+=dy[dir];
			x0=min(x0,x);
			y0=min(y0,y);
			B[i]=ii(x,y);
			a=max(a,x);
			b=max(b,y);
			//cout<<x<<" "<<y<<endl;
		}

		printf("%d %d\n",a-x0+3,b+2);
		
		A[1-x0][1-y0]=1;
		for(int i=0;i<s.length();i++)
			A[B[i].first-x0+1][B[i].second]=1;
		
		for(int i=a-x0+2;i>=0;i--) {
			for(int j=0;j<(b+2);j++) {
				if(A[i][j]==1)
					printf(".");
				else
					printf("#");
			}
			printf("\n");
		}
	}

	return 0;
}

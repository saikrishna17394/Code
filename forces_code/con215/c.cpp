#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 99999999
typedef long long int lli;

int A[100000][3]={0};

int main() {
	string s;
	int len,m,a,b,val1,val2,num;

	cin>>s;
	len=s.length();
	A[0][s[0]-'x']++;

	for(int i=1;i<len;i++) {
		for(int j=0;j<3;j++)
			A[i][j]=A[i-1][j];
		A[i][s[i]-'x']++;
	}
	cin>>m;
	while(m--) {
		scanf("%d %d",&a,&b);
		a--;
		b--;

		if((b-a)<2) {
			printf("YES\n");
		}
		else {
			val1=0;
			val2=9999999;
			for(int i=0;i<3;i++) {
				num=A[b][i];
				if(a)
					num-=A[a-1][i];
				val1=max(val1,num);
				val2=min(val2,num);
			}

			if(val1>(val2+1))
				printf("NO\n");
			else
				printf("YES\n");
		}
	}


	return 0;
}
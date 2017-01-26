#include <bits/stdc++.h>

#define lli long long int
using namespace std;

int A[10000]={0};

int main() {

	for(int i=2;i<100;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<10000;j+=i)
				A[j]=i;
		}
	}

	for(int i=100;i<=9999;i++) {
		printf("%d:",i );

		int ans=0,num=i;

		while(num>1) {
			if(A[num]==0) {
				num=1;
			}
			else {
				int val=A[num];
				while(num%val==0)
					num/=val;
			}
			ans++;
		}

		ans=1<<(ans-1);

		// ans=(ans*(ans-1))/2;
		printf("%d",ans );
		if(i<9999)
			printf(",");
	}
	printf("\n");

	return 0;
}
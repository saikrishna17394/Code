#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define lim 10000000
using namespace std;
int A[lim+1]={0};
int B[lim+1],cnt,ans=0;
int main() {
	int k=sqrt(lim);
	for(int i=2;i<=k;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<=lim;j+=i)
				A[j]=i;
		}
	}

	B[1]=1;
	B[2]=2;
	for(int i=3;i<=lim;i++) {
		if(A[i]==0)
			B[i]=2;
		else {
			cnt=0;
			k=i;
			while(k%A[i]==0) {
				cnt++;
				k/=A[i];
			}
			B[i]=B[k]*(cnt+1);
		}
		if(B[i]==B[i-1])
			ans++;
	}

	//cout<<B[14]<<" "<<B[15]<<endl;
	cout<<ans<<endl;
	return 0;
}
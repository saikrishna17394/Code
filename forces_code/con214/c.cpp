#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 999999999
typedef long long int lli;

int main() {
	int n,k,A[101],B[101],s1[10001],s2[10001],temp[10001];
	cin>>n>>k;

	for(int i=1;i<=n;i++)
		cin>>A[i];
	for(int j=1;j<=n;j++)
		cin>>B[j];

	int ans=-1;
	memset(s1,0,sizeof s1);
	memset(s2,0,sizeof s2);

	for(int i=1;i<=n;i++) {
		for(int j=0;j<10001;j++)
			temp[j]=s1[j];

		s1[A[i]]=i;
		for(int j=A[i]+1;j<10001;j++) {
			if(temp[j-A[i]]) {
				cout<<j<<" "<<i<<endl;
				s1[j]=i;
			}
		}

		for(int j=0;j<10001;j++)
			temp[j]=s2[j];

		s2[B[i]]=i;
		for(int j=B[i]+1;j<10001;j++) {
			if(temp[j-B[i]]) {
				cout<<j<<" "<<i<<endl;
				s2[j]=i;
			}
		}


		for(int j=(10000)/k;j>0;j--) {
			if(s1[j*k]==i && s2[j]==i) {
				cout<<j<<" "<<k<<" "<<i<<endl;
				ans=max(ans,j*k);
				break;
			}
		}
	}

	printf("%d\n", ans);


	return 0;
}
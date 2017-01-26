#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

int A[1010]={0};

int main(){ 
	// cin.sync_with_stdio(]false);
	
	int n;

	cin>>n;

	int ans=0;

	vector<int> v;

	for(int i=2;i<=n;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<=n;j+=i)
				A[j]=i;
			v.push_back(i);
			continue;
		}
		int val=i;

		while(val%A[i]==0)
			val/=A[i];

		if(val==1)
			v.push_back(i);

	}
	cout<<v.size()<<endl;

	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	printf("\n");

	return 0;
}
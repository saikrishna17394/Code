#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

lli n,m;
lli A[1000001],num;
lli x1,x2,Y1,y2;

int main() {
	cin>>n;
	memset(A,0,sizeof A);

	while(n--) {
		cin>>num;
		A[num]++;
	}

	for(int i=1;i<1000001;i++) {
		A[i]+=A[i-1];
	}

	lli ans=0;
	cin>>m;
	while(m--) {
		cin>>x1>>Y1>>x2>>y2;
		lli d1=sqrt((double)(x1*x1+Y1*Y1));
		lli d2=sqrt((double)(x2*x2+y2*y2));


		if(d1>d2)
			swap(d1,d2);
		d1=min(d1,1000000ll);
		d2=min(d2,1000000ll);
		ans+=A[d2]-A[d1];
	}
	cout<<ans<<endl;


	return 0;
}
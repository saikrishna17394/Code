#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int main(){ 
	lli t,w,d,s,r;

	cin>>t;

	while(t--) {
		// cin>>w>>d>>s>>r;
		scanf("%lld %lld %lld %lld",&w,&d,&s,&r);


		// printf("bro\n");

		double ans,ans1;

		if(s>=r) {
			lli val=w*w+d*d;
			ans=sqrt((double)val);
			ans=ans/(double)s;
			ans1=0;
		}
		else {
			double th=(double)s/(double)r;
			// cout<<" "<<th<<endl;
			th=asin(th);
			// cout<<th<<endl;
			ans=(double)w/((double)s*cos(th));

			ans+=((double)d- ((double)w*tan(th)) )/(double)r;
			ans1=(double)d-(double)w*tan(th);

		}
		printf("%.6f %.6f\n",ans1, ans);
	}

	return 0;
}
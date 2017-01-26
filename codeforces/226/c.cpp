#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010
#define vi vector<long long int>
#define vvi vector<vector<long long int> >

using namespace std;

lli m,l,r,k;
set<lli> s;

void solve(lli n) {
	lli num=1;
	s.insert(num);
	lli r=0;
	lli q=n;
	// cout<<n<<" : "<<endl;
	while(num<n) {
		num+=r/q;

		if(r%q!=0 || r==0)
			num++;
		// cout<<num<<" "<<r<<" "<<q<<endl;
		s.insert(num-1);
		q=n/num;
		r=n%num;
	}
	s.insert(n);
	// cout<<"------\n";
}

vvi mul(vvi a,vvi b) {
	vvi ret(2,vi(2,0));

	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			for(int k=0;k<2;k++) {
				ret[i][j]+=(a[i][k]*b[k][j])%m;
				ret[i][j]%=m;
			}
		}
	}
	return ret;
}


lli fib(lli n) {
	if(n<=2)
		return ((lli)1)%m;

	n-=2;
	vvi ret(2,vi(2,0));
	ret[0][0]=1;
	ret[1][1]=1;

	vvi a(2,vi(2,0));
	a[0][0]=1;
	a[0][1]=1;
	a[1][0]=1;

	while(n>0) {
		if(n%2==1)
			ret=mul(ret,a);
		a=mul(a,a);
		n/=2;
	}

	return (ret[0][0]+ret[0][1])%m;
}

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>m>>l>>r>>k;


	solve(l);
	solve(r);


	lli ans=0;

	for(set<lli>::iterator it=s.begin();it!=s.end();it++) {
		// cout<<*it<<endl;
		lli val=r/(*it);
		val-=(l-1)/(*it);

		if(val>=k) {
			ans=*it;
		}
	}

	ans=fib(ans);

	cout<<ans<<endl;

	return 0;
}
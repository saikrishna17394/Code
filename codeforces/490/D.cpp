#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int A[4][2]={0};

lli solve(lli a,int idx) {
	// cout<<
	while(a%3==0) {
		A[3][idx]++;
		a/=3;
	}
	while(a%2==0) {
		A[2][idx]++;
		a/=2;
	}
	return a;
}

lli a1,b1,a2,b2;
int main(){ 
	cin.sync_with_stdio(false);

	cin>>a1>>b1>>a2>>b2;
	memset(A,0,sizeof A);

	lli num1=1,num2=1;	
	num1=solve(a1,0);
	num1*=solve(b1,0);

	num2=solve(a2,1);
	num2*=solve(b2,1);

	if(num1!=num2) {
		printf("-1\n");
		return 0;
	}

	lli ans=0;
	while(A[3][0]!=A[3][1]) {
		// cout<<"w\n";
		ans++;
		if(A[3][0]<A[3][1]) {
			if(a2%3==0) {
				a2/=3;
				a2*=2;
			}
			else {
				b2/=3;
				b2*=2;
			}
			A[2][1]++;
			A[3][1]--;
		}
		else {
			if(a1%3==0) {
				a1/=3;
				a1*=2;
			}
			else {
				b1/=3;
				b1*=2;
			}
			A[2][0]++;
			A[3][0]--;
		}
	}

	while(A[2][0]!=A[2][1]) {
		ans++;

		if(A[2][0]>A[2][1]) {
			if(a1%2==0)
				a1/=2;
			else
				b1/=2;
			A[2][0]--;
		}
		else {
			if(a2%2==0)
				a2/=2;
			else
				b2/=2;
			A[2][1]--;
		}
	}

	cout<<ans<<endl;
	cout<<a1<<" "<<b1<<endl;
	cout<<a2<<" "<<b2<<endl;
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long int lli;

int main() {
	lli a,A[40000]={0},val,len,ans;
	cin>>a;
	string s;
	cin>>s;
	
	len=s.length();

	for(lli i=0;i<len;i++) {
		val=0;
		for(lli j=i;j>=0;j--) {
			val+=s[j]-'0';
			A[val]++;
		}
	}

	if(a==0) {
		len=len*(len+1);
		len/=2;
		ans=2*A[0]*len;
		ans-=A[0]*A[0];
		cout<<ans<<endl;
		return 0;
	}
	ans=0;

	lli k=sqrt(a);
	for(lli i=1;i<=k;i++) {
		if(i*i==a) {
			ans+=A[i]*A[i];
			continue;
		}
		if(a%i==0 && (a/i)<40000) {
			// cout<<i<<" "<<a/i<<endl;
			// cout<<A[i]<<" "<<A[a/i]<<endl; 
			ans+=2*A[i]*A[a/i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
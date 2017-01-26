#include <bits/stdc++.h>
#define lli long long int
#define ii pair<long long int,long long int>

using namespace std;

lli tree[100001]={0},n;

void upd(lli idx,lli val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

lli read(lli idx) {
	lli ret=0;
	while(idx>0) {
		ret+=tree[idx];
		idx-=idx&-idx;
	}
	return ret;
}

string s;
int main() {
	cin>>n;
	
	cin>>s;
	
	for(lli i=0;i<n;i++) {
		if(s[i]=='H') {
			upd(1,1);
			upd(n-i,-1);
		}
		else {
			upd(1,-1);
			upd(n-i,1);
		}
	}

	lli ans=0;
	lli add=0;
	
	for(lli i=n;i>0;i--) {
		lli val=read(i)+add;
		
		if(i==1) {
			if(val!=0)
				ans=val;
			break;
		}
		
		add=val/2;
		
		val%=2;
				
		if(val!=0)
			ans=val;
		//cout<<i<<" "<<val<<endl;
	}
	
	if(ans==0)
		printf("HM\n");
	else if(ans>0)
		printf("H\n");
	else
		printf("M\n");
		
	return 0;
}

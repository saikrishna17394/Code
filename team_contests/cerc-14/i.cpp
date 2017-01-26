#include <bits/stdc++.h>
#define ii pair<int,int>
#define inf 999999999
#define lli long long int

using namespace std;

lli t,n;
lli A[100000];

int main() {
	cin.sync_with_stdio(false);
	
	cin>>t;
	
	while(t--) {
		cin>>n;
		int idx=0,num;
		
		char prev='a',ch;
		
		
		//memset(A,0,sizeof A);
		
		while(n--) {
			cin>>num>>ch;
			if(ch!=prev)
				A[idx++]=(lli)num;
			else
				A[idx-1]+=(lli)num;
			prev=ch;
		}
		
		if(idx==1) {
			cout<<A[0]<<endl;
			continue;
		}
		
		lli B[2],C[2];
		
		memset(B,0,sizeof B);
		
		for(int i=0;i<idx;i++)
			B[i%2]+=A[i];
		
		memset(C,0,sizeof C);
		C[(idx-1)%2]+=A[idx-1];
		
		int ans=0;
		
		for(int i=idx-2;i>=0;i--) {
			
			if(i%2==0) {
				lli num=B[0]*C[1];
				
				if(num%B[1]==0) {
					num/=B[1];
					
					if(num>C[0] && num<=(C[0]+A[i]))
						ans++;
				}
			}
			else {
				lli num=C[0]*B[1];
				
				if(num%B[0]==0) {
					num/=B[0];
					
					if(num>C[1] && num<=(C[1]+A[i]))
						ans++;
				}
			}
			C[i%2]+=A[i];				
		}
		
		cout<<ans<<endl;
		
	}
		
	return 0;
}

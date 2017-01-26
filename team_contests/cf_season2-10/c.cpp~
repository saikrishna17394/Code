#include <bits/stdc++.h>

using namespace std;


int s;


int main() {
	cin>>s;
	
	if(s==2 || s==5) {
		printf("Impossible\n");
		return 0;
	}	
	
	int n=1;
	int val=0;
	
	while(1)  {
		val+=n-1;
		if(val+(n-1)>=s) {
			break;
		}
		n++;
	}
	int m=n*(n-1)/2;
	m-=(s-val);
	cout<<n<<" "<<m<<endl;
	if(m==0)
		return 0;
	
	if((s-val)<(n-1)) {
		for(int i=2;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				cout<<i<<" "<<j<<endl;
	}
	else {
		for(int i=2;i<=n;i++)
			for(int j=i+1;j<=n;j++) {
				if(i==3 && j==4)
					continue;
				cout<<i<<" "<<j<<endl;
			}	
	}
	
	int cnt=n-1-min(n-2,s-val);
	
	
	for(int i=0;i<cnt;i++)
		cout<<"1 "<<i+2<<endl;
	
	

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("kickdown.in","r",stdin);
	freopen("kickdown.out","w",stdout);
	string s1,s2;
	cin>>s1>>s2;
	
		
	int ans = 999999999;
	int n1=s1.length(),n2=s2.length();
	
	for(int i=0; i<n1+n2;i++)
	{
		bool ok=true;

		for(int j=0;j<n2;j++) {
			if((j+i)>=n2 && (j+i)<(n1+n2)) {
				if((s2[j]+s1[j+i-n2]-'0')>'3')
					ok=false;
			}
		}
		
		if(ok)
		{
			int l=min(i,n2);
			int r=max(n1+n2-1,i+n2-1);
			ans=min(ans,r-l+1);

		}
		
	}
	cout<<ans<<endl;
	return 0;
}

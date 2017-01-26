#include <bits/stdc++.h>

using namespace std;

set<string> v[1001];

int main() {
	string s;
	int n;
	cin>>s;
	n=s.length();


	for(int i=0;i<n;i++) {
		string s1="";
		s1+=s[i];
		for(int j=i+1;j<n;j++) {
			int idx=1;
			string s2=s1;
			int a=i+1,b=j+1;
			while(b<=n) {
				//cout<<a<<" "<<b<<endl; 
				s2+=s[b-1];
				idx++;
				//cout<<idx<<" "<<s2<<endl;
				int t=b;
				b=a+b;
				a=t;
			}
			v[idx].insert(s2);
		}
	}

	int ans=0;
	
	for(int i=2;i<=n;i++)
		ans+=(int)v[i].size();
	printf("%d\n",ans);	
	return 0;
}

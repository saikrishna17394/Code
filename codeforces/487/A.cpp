#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

bool check(int h1,int a1,int d1,int h2,int a2,int d2) {
	if((a2-d1)<=0)
		return false;
	int t1=h1/(a2-d1);
	if((h1%(a2-d1))!=0)
		t1++;
	if((a1-d2)<=0)
		return true;
	
	int t2= h2/(a1-d2);

	if(h2%(a1-d2)==0)
		t2--;

	if(t2>=t1)
		return true;
	return false;
}

int h1,a1,d1,h2,a2,d2,h,a,d;
// int A[10001][201][101];
int ans;

int main(){ 
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	ans=inf;

	cin>>h2>>a2>>d2;
	cin>>h1>>a1>>d1;
	cin>>h>>a>>d;

	for(int j=0;j<201;j++) {
		for(int k=0;k<101;k++) {
			for(int i=0;i<10001;i++) {
				if(check(h1,a1,d1,h2+i,a2+j,d2+k)) {
					ans=min(ans,i*h+a*j+k*d);
					break;
				}
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}
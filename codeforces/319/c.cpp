#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

lli n,A[100000],m[100000];
lli c[100000];

int lines[100000];

int idx=0;

bool check(int x1, int x2,int x) {
	if((m[x1]*x+c[x1])>(m[x2]*x+c[x2]))
		return true;
	return false;
}

bool check1(int x1,int x2,int x3,int x4) {
	x1=lines[x1];
	x2=lines[x2];
	x3=lines[x3];
	x4=lines[x4];

	if( ((double)(c[x1]-c[x2])*(double)(m[x4]-m[x3])) >= ((double)(c[x3]-c[x4])*(double)(m[x2]-m[x1])) )
		return true;
	return false;
}

int main(){ 
	cin.sync_with_stdio(false);
	
	cin>>n;
	for(lli i=0;i<n;i++)
		cin>>A[i];
	for(lli i=0;i<n;i++)
		cin>>m[i];

	c[0]=0;

	lines[idx++]=0;
	int k=0;

	for(lli i=1;i<n;i++) {
		while(k>=idx)
			k--;

		while( ((k+1)<idx) &&  check(lines[k],lines[k+1],A[i]))
			k++;
		int pos=lines[k];
		c[i]=m[pos]*A[i]+c[pos];

		lines[idx++]=i;


		while(idx>=3 && check1(idx-3,idx-2, idx-2,idx-1)) {
			lines[idx-2]=lines[idx-1];
			idx--;
		}
	}


	cout<<c[n-1]<<endl;
	return 0;
}
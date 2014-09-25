#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

int m,n,cnt,A[100010],a;

struct typ {
	int t;
	int num;
	int l,c;
};

lli C[100010];
typ B[100010];

int main() {
	scanf("%d",&m);
	cnt=0;

	for(int i=0;i<m;i++) {
		scanf("%d",&B[i].t);
		if(B[i].t==1)
			scanf("%d",&B[i].num);
		else
			scanf("%d %d",&B[i].l,&B[i].c);
	}

	scanf("%d",&n);

	for(int i=0;i<n;i++)
		cin>>C[i];

	lli pos=1;
	int i=0;

	while(i<m && pos<=100000) {
		if(B[i].t==1) {
			A[pos++]=B[i].num;
		}
		else {
			for(int j=0;j<B[i].c;j++) {
				bool ok=false;
				for(int k=1;k<=B[i].l;k++) {
					A[pos++]=A[k];
					if(pos>100000) {
						ok=true;
						break;
					}
				}
				if(ok)
					break;
			}
		}
		i++;
	}

	i=0;
	int j=0;
	lli len=1,val,val1;

	while(i<m && j<n) {
		// cout<<i<<" "<<j<<" "<<n<<" "<<m
		if(B[i].t==1) {
			if(C[j]==len) {
				cout<<B[i].num<<" ";
				j++;
			}
			len++;
		}
		else {
			val=len+(lli)B[i].l*(lli)B[i].c;
			val--;

			while(C[j]<=val && j<n) {
				val1=C[j]-len;
				val1=val1%(lli)B[i].l;
				cout<<A[val1+1]<<" ";
				j++;
			}

			len=val+1;
		}
		i++;
	}
	cout<<endl;
	// cout<<pos<<endl;
	// for(int i=1;i<pos;i++)
	// 	cout<<A[i]<<" ";
	// cout<<endl;

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#include <map>
#define lli long long int
#define lim 1000200

using namespace std;

typedef pair<int,int> ii;

int frac_part(int n) {
	int l=1,r=n,mid;

	while(l!=r) {
		 // cout<<l<<" "<<r<<endl;
		mid=(l+r)/2;
		mid++;
		// cout<<mid<<" "<<mid*mid<<endl;
		if(mid*mid>n)
			r=mid-1;
		else
			l=mid;

	}
	return l;
}
int main() {
	int num,ans=0,den,frac,pos,num1;

	map<ii,int> m;

	for(int i=1;i<=10000;i++) {
		frac=frac_part(i);

		if(frac*frac==i)
			continue;
		m.clear();
		
		pos=1;

		num=frac;
		den=1;
		// cout<<"nayna "<<i<<endl;
		while(1) {
			// cout<<i-num*num<<" "<<den<<endl;
			den=(i-num*num)/den;

			// cout<<(frac+num)/den<<endl;
			num=num-((frac+num)/den)*den;

			num*=-1;
			// cout<<num<<" yo "<<den<<endl;
			if(m.find(ii(num,den)) != m.end()) {
				int prev_pos=m[ii(num,den)];
				if((pos-prev_pos)%2==1) {
					// cout<<i<<endl;
					ans++;
				}
				break;
			} 
			m[ii(num,den)]=pos;
			pos++;
		}
	}

	cout<<ans<<endl;

	return 0;
}
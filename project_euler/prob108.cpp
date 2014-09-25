#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
using namespace std;

int main() {
	lli num=2,ans;

	while(num++) {
		ans=1;
		//cout<<num<<" :\n";
		for(lli i=num+1;i<2*num;i++) {
			if((num*i)%(i-num)==0) {
				ans++;
				//cout<<i<<" "<<(num*i)/(i-num)<<endl;
			}
		}


		//if(ans>500)
		//	cout<<num<<" "<<ans<<endl;
		if(ans>1000)
			break;
	}
	cout<<num<<" "<<ans<<endl;
	return 0;
}
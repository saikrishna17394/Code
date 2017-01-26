#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;

int A[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int d,m,y;
int main() {
	cin>>d>>m>>y;

	m--;

	int ans=5;

	for(int i=1;i<y;i++) {
		ans=(ans+365)%7;

		if(y%4==0) {
			if(y%100!=0)
				ans++;
			else if(y%400==0)
				ans++;
			else
				;
		}
		ans%=7;

	}

	for(int i=0;i<m;i++)
		ans+=A[i];
	ans%=7;

	ans+=d;
	ans%=7;

	if(ans==0) {
		printf("Sunday\n");
	}
	else if(ans==1) {
		printf("Monday\n");
	}
	else if(ans==2) {
		printf("Tuesday\n");
	}
	else if(ans==3)
		printf("Wednesday\n" );
	else if(ans==4)
		printf("Thursday\n");
	else if(ans==5)
		printf("Friday\n");
	else
		printf("Saturday\n");
	
	// cout<<ans<<endl;
	return 0;
}
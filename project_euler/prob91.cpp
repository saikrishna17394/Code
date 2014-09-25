#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define lim 1000200
using namespace std;

int main() {
	int ans=0;
	int x2,y2;
	int A[3];

	for(int x1=0;x1<=50;x1++) {
		//cout<<x1<<"\n";
		for(int y1=0;y1<=50;y1++) {
			if(x1==0 & y1==0)
				continue;
			if(y1<50) {
				y2=y1+1;
				x2=x1;
			}
			else {
				y2=0;
				x2=x1+1;
			}

			for(;x2<=50;x2++) {
				for(;y2<=50;y2++){
					//cout<<x2<<" "<<y2<<" "<<endl;
					A[0]=x1*x1+y1*y1;
					A[1]=x2*x2+y2*y2;
					A[2]=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
					sort(A,A+3);
					if(A[2]==(A[1]+A[0]))
						ans++;
						//cout<<val1<<" "<<val2<<" "<<val3<<endl;

				}
				y2=0;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
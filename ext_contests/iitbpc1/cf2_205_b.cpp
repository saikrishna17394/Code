#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int n,A[200];
map<int,int> m;

int a[100]={0},b[100]={0};

int main() {
	cin>>n;

	for(int i=0;i<2*n;i++) {
		cin>>A[i];
		m[A[i]]++;
	}

	int l=0,r=0,zer_l=0,zer_r=0,num1=0,num2=0;

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		if(it->second > 1) {
			l++;
			r++;
			a[it->first]=(it->second)/2;
			b[it->first]=(it->second)/2;

			if(it->second%2==1) {
				if(zer_l>=zer_r) {
					b[it->first]++;
					zer_r++;
				}
				else {
					a[it->first]++;
					zer_l++;
				}
			}
			num1+=a[it->first];
			num2+=b[it->first];
		}
	}
	num1=n-num1;
	num2=n-num2;

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		if(it->second==1) {
			if(num1) {
				num1--;
				a[it->first]++;
				l++;
			}
			else {
				b[it->first]++;
				r++;
			}
		}
	}

	printf("%d\n", l*r);

	for(int i=0;i<2*n;i++) {
		if(a[A[i]]>0) {
			a[A[i]]--;
			printf("1 ");
		}
		else {
			printf("2 ");
		}
	}
	printf("\n");
	return 0;
}
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

string s;

int main() {
	cin>>s;

	lli e=0,o=0,a=0,b=0,rec=-1;

	for(int i=0;i<s.length();i++) {
		if(s[i]=='a') {
			if(rec==-1) {
				o++;
				b=1;
			}
			else {
				if((i-rec)%2==1)
					swap(a,b);
				b++;
				o+=b;
				e+=a;
			}
			rec=i;
		}
	}

	a=0;
	b=0;
	rec=-1;

	for(int i=0;i<s.length();i++) {
		if(s[i]=='b') {
			if(rec==-1) {
				o++;
				b=1;
			}
			else {
				if((i-rec)%2==1)
					swap(a,b);
				b++;
				o+=b;
				e+=a;
			}
			rec=i;
		}
	}

	cout<<e<<" "<<o<<endl;

	return 0;
}
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
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	string s;

	while(getline(cin,s)) {
		// cout<<s<<endl;
		int n=s.length();

		string s1="";
		bool ok=false;

		for(int i=0;i<n;i++) {
			if(s[i]=='/') {
				s1+=s[i];
				if(i+1<n  && s[i+1]=='/') {
					ok=true;
					s1+=s[i+1];
					i++;
				}
			}
			else if(s[i]=='-') {
				
				if(i+1<n  && s[i+1]=='>') {
					if(ok) {
						s1+=s[i];
						s1+=s[i+1];
						i++;
					}
					else {
						s1+=".";
						i++;
					}
				}
				else {
					s1+=s[i];
				}
			}
			else
				s1+=s[i];
		}
		cout<<s1<<endl;
	}


	return 0;
}
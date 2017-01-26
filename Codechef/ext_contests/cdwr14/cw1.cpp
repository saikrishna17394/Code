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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n;
string s,s1,s2;
int len,len1;

int main() {

	while(scanf("%d",&n)!=EOF) {
		cin>>s;

		while(n--) {
			cin>>s1;

			len=s.length();
			len1=s1.length();
			s2="";
			for(int i=0;i<len;i++) {
				bool ok=true;
				for(int j=0;j<len1;j++) {
					if((i+j)>=len) {
						ok=false;
						break;
					}
					if(s[i+j]!=s1[j]) {
						ok=false;
						break;
					}
				}
				if(!ok)
					s2+=s[i];
				else
					i+=(len1-1);
			}
			s=s2;
			// cout<<s<<endl;
		}

		if(s.length()==0)
			printf("0\n");
		else
			cout<<s<<endl;
	}

	return 0;
}
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
#define ii pair<int,char>

#define mod 1000000007
#define inf 999999999
#define lim 1000010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int t,A[26],len;
	string s,s1;
	ii B[26];
	int cipher[26];

	inp(t);

	while(t--) {
		getline(cin,s);
		getline(cin,s1);

		memset(A,0,sizeof A);
		len=s1.length();

		for(int i=0;i<len;i++) {
			if(s1[i]>='a' && s1[i]<='z')
				A[s1[i]-'a']++;
			else if(s1[i]>='A' && s1[i]<='Z')
				A[s1[i]-'A']++;
			else
				;
		}

		for(int i=0;i<26;i++)
			B[i]=make_pair(A[i],'a'+i);
		
		sort(B,B+26);
		
		for(int i=0;i<26;i++)
			cipher[B[i].second-'a']=s[i]-'a';

		for(int i=0;i<len;i++) {
			if(s1[i]>='a' && s1[i]<='z')
				printf("%c",cipher[s1[i]-'a']+'a');
			else if(s1[i]>='A' && s1[i]<='Z')
				printf("%c",cipher[s1[i]-'A']+'A');
			else
				printf("%c", s1[i]);
		}
		printf("\n");
	}



	return 0;
}
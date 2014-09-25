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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[10];
int B[10];

int main() {
	int t;
	string s;

	inp(t);

	while(t--) {
		cin>>s;

		memset(A,0,sizeof A);

		if(s.length()<=3) {

			if(s.length()==1) {
				int num=s[0]-'0';
				if(num%8==0)
					printf("YES\n");
				else
					printf("NO\n");
			}

			else if(s.length()==2) {
				int num=s[0]-'0';
				int num1=s[1]-'0';

				if((num1*10+num)%8==0 || (num*10+num1)%8==0)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else {
				int C[3];
				for(int i=0;i<3;i++)
					C[i]=s[i]-'0';
				sort(C,C+3);
				bool ok=true;
				do {
					int num=0;
					for(int i=0;i<3;i++)
						num=num*10+C[i];
					if(num%8==0) {
						ok=false;
						printf("YES\n");
						break;
					}
				} while(next_permutation(C,C+3));
				if(ok)
					printf("NO\n");
			}

			continue;
		}
		// cout<<s<<endl;
		for(int i=0;i<s.length();i++) 
			A[s[i]-'0']++;

		bool ok=true;

		for(int i=0;i<1000;i+=8) {
			memset(B,0,sizeof B);
			int num=i;

			for(int j=0;j<3;j++) {
				B[num%10]++;
				num/=10;
			}

			bool man=false;
			for(int j=0;j<10;j++) {
				if(B[j]>A[j]) {
					man=true;
					break;
				}
			}
			if(man)
				continue;
			printf("YES\n");
			ok=false;
			break;
		}
		if(ok)
			printf("NO\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int m,f,A[100];
int n;
int q;

int ans[1000]={0};

int B[1000][1000]={0};


int main(){ 
	freopen("easy.in", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("easy.out", "w", stdout);

	string s;
	cin>>s;

	string s1;
	
	int len=s.length(),i=0;


	while(i<len) {
		if(s[i]!='-') {
			s1+=s[i];
			i++;
			continue;
		}

		s1+=s[i++];

		s1+=s[i++];

		while(i<len && s[i]!='+' && s[i]!='-') {
			if(s[i]!='0') {
				s1+='+';
				s1+=s[i++];
				break;
			}
			if(i==(len-1) || s[i+1]=='+' || s[i+1]=='-') {
				s1+='+';
				s1+=s[i++];
				break;
			}
			s1+='+';
			s1+=s[i++];
		}

	}
	cout<<s1<<endl;
	return 0;
}
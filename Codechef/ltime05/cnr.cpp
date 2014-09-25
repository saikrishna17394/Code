#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

string add(string s1,string s2) {
	int len1=s1.length(),len2=s2.length();

	if(len1<len2) {
		for(int i=len1;i<len2;i++)
			s1+="0";
		len1=len2;
	}
	else if(len2<len1) {
		for(int i=len2;i<len1;i++)
			s2+="0";		
		len2=len1;
	}
	else
		;
	string s;
	int carry=0;
	for(int i=0;i<len1;i++) {
		s+=('0'+(s1[i]-'0'+s2[i]-'0'+carry)%10);
		carry=(s1[i]-'0'+s2[i]-'0'+carry)/10;
	}
	if(carry)
		s+=(carry+'0');
	return s;
}

bool check(string s1,string s2) {
	int len1=s1.length(),len2=s2.length();
	if(len1>len2)
		return true;
	if(len2>len1)
		return false;
	for(int i=len1-1;i>=0;i--) {
		if(s1[i]>s2[i])
			return true;
		if(s1[i]<s2[i])
			return false;
	}
	return false;
}

string sub(string s1,string s2) {
	int len1=s1.length(),len2=s2.length();

	string s;

	for(int i=0;i<len1;i++) {
		// /cout<<s1[i]<<" "<<s2[i]<<endl;
		if(i>=len2) {
			s+=s1[i];
		}
		else {
			if(s1[i]>=s2[i])
				s+=('0'+s1[i]-s2[i]);
			else {
				s+=('0'+s1[i]-s2[i]+10);
				s1[i+1]--;
			}
		}
		// cout<<s[i]<<endl;
	}
	
	

	int i=len1-1;
	for(;i>=0;i--) {
		if(s[i]=='0')
			;
		else
			break;
	}
	s1="";
	// cout<<s1<<" "<<s<<endl;
	for(int j=0;j<=i;j++) {

		s1+=s[j];
	}
	// cout<<s1<<endl;
	if(s1.length()==0)
		s1+="0";
	return s1;	
}
string ncr[351][351];

void find(lli n,lli k,string m) {
	// cout<<"\n"<<n<<" "<<m<<" "<<k<<endl;
	if(n==1) {
		if(k==0)
			printf("0\n");
		else
			printf("1\n");
		return;
	}
	if(n==k) {
		for(int i=0;i<n;i++)
			printf("1");
		printf("\n");
		return;
	}
	// cout<<"\n"<<m<<" "<<ncr[n-1][k]<<endl;
	// cout<<sub(m,ncr[n-1][k])<<endl<<endl;
	if(check(m,ncr[n-1][k])) {
		printf("1");
		find(n-1,k-1,sub(m,ncr[n-1][k]));
	}
	else {
		printf("0");
		find(n-1,k,m);
	}
}

int main() {
	lli t,n,k;
	string s,m;

	ncr[1][0]="1";
	ncr[1][1]="1";

	//Here 400 is enuf to be treated as infinity
	for(int i=2;i<351;i++) {
		ncr[i][0]="1";
		ncr[i][i]="1";
		for(int j=1;j<i;j++) {
			ncr[i][j]=add(ncr[i-1][j],ncr[i-1][j-1]);
			// cout<<ncr[i][j]<<" ";
		}
		// cout<<endl;
	}
	inp(t);
	while(t--) {
		inp(n);
		inp(k);
		cin>>s;

		m="";
		int i=0;
		for(;i<s.length()-1;i++)
			if(s[i]!='0')
				break;

		if(i==s.length())
			m+="0";
		for(int j=s.length()-1;j>=i;j--)
			m+=s[j];

		// cout<<m<<" "<<ncr[n][k]<<endl;

		if(check(m,ncr[n][k]))
			printf("-1\n");
		else {
			find(n,k,m);
		}
	}

	return 0;
}
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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
string s[10];

pair<int,string> A[10];

int main() {
	s[0]="Dhaval";
	s[1]="Shivang";
	s[2]="Bhardwaj";
	s[3]="Rishab";
	s[4]="Maji";
	s[5]="Gaurav";
	s[6]="Dhruv";
	s[7]="Nikhil";
	s[8]="Rohan";
	s[9]="Ketan";
	

	for(int i=0;i<10;i++) {
		inp(A[i].first);
		A[i].second=s[i];
	}
	sort(A,A+10);

	// for(int i=0;i<10;i++) {
	// 	cout<<A[i].first<<" "<<A[i].second<<endl;
	// }

	int l=0,r=9;

	int x=0;

	while(l<=r) {
		if(x==0) {
			cout<<A[r].second<<endl;
			r--;
		}
		else {
			cout<<A[l].second<<endl;
			l++;
		}
		x^=1;
	}
	return 0;
}
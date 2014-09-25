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

int g[100010][26],n,k,nodes;
string s;

int solve(int cur) {

	for(int j=0;j<26;j++) {
		if(g[cur][j]) {
			if(solve(g[cur][j])==0) {
				return 1;
			}
		}
	}

	return 0;
}

int solve1(int cur) {

	int val=1;
	for(int j=0;j<26;j++) {
		if(g[cur][j]) {
			if(solve1(g[cur][j])==0) {
				return 1;
			}
			val=0;
		}
	}

	return val;
}

int main() {
	memset(g,0,sizeof g);
	cin>>n>>k;

	nodes=1;

	for(int i=0;i<n;i++) {
		cin>>s;

		int cur=0;
		for(int j=0;j<s.length();j++) {
			if(g[cur][s[j]-'a']==0) {
				g[cur][s[j]-'a']=nodes++;
				cur=nodes-1;
			}
			else {
				cur=g[cur][s[j]-'a'];
			}
		}
	}

	int win=solve(0);

	int lose=solve1(0);

	if(win==1 && lose==1)
		printf("First\n");
	else if(win==1) {
		if(k%2==1)
			printf("First\n");
		else
			printf("Second\n");
	}
	else {
		printf("Second\n");

	}
	return 0;
}
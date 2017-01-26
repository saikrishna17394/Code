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

string s[6]= 
{"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"};

int main() {
	int n;

	cin>>n;

	for(int i=1;i<=4;i++) {
		if(n==0)
			break;
		n--;
		s[i][1]='O';
	}

	int idx=3;
	while(n>0) {

		for(int i=1;i<=4;i++) {
			if(n==0)
				break;
			if(i==3)
				continue;
			n--;
			s[i][idx]='O';
		}
		idx+=2;
	}

	for(int i=0;i<6;i++)
		cout<<s[i]<<endl;
	return 0;
}
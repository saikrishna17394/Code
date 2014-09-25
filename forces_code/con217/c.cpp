#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 99999999
typedef long long int lli;

const int maxn = 5000;

vector<int> adj[maxn];
int mark[maxn], stamp, match[maxn];

// Hungray, find augment path
inline bool augment(int x)
{
    for (int i = 0; i < adj[x].size(); ++ i) {
        int y = adj[x][i];
        if (mark[y] == stamp) {
            continue;
        }
        mark[y] = stamp;
        if (match[y] == -1 || augment(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
	int n,m,A[5000];

	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(A[i]!=A[j])
				adj[i].push_back(j);

	memset(mark, -1, sizeof(mark));
	memset(match, -1, sizeof(match));
	stamp = 0;
	int maxMatch = 0;
	for (int i = 0; i < n; ++ i) {
	    ++ stamp;
	    if (augment(i)) {
	        ++ maxMatch;
	    }
	}
	printf("%d\n", maxMatch);

	for(int i=0;i<n;i++) {
		if(match[i]==-1)
			printf("%d %d\n", A[i],A[i]);
		else
			printf("%d %d\n",A[i],A[match[i]]);
	}
	return 0;
}
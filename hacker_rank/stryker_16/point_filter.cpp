#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<double,double> ii;
typedef pair<double,int> di;
using namespace std;

int n,b;

int B[lim]={0};
map<int,int> pos;
pair<di,ii> A[lim];

int main() {
	cin>>n>>b;

	for(int i=0;i<n;i++) {
		int k;
		double x,y,z;
		cin>>k>>x>>y>>z;
		A[i]=make_pair(di(z,k),ii(x,y));
	}

	sort(A,A+n);

	for(int i=0;i<n;i++) {
		pos[A[i].first.second] = i;
	}

	int idx = n-b;

	for(int i = idx; i < n; i++)
		B[i] = 1;

	char ch;
	int k;

	while(cin>>ch) {
		cin>>k;

		if(pos.find(k) == pos.end()) {
			printf("Point doesn't exist in the bucket.\n");
			continue;
		}

		int pos1 = pos[k];
		double x,y,z;
		z=A[pos1].first.first;
		x=A[pos1].second.first;
		y=A[pos1].second.second;

		// cout<<pos1<<" "<<k<<" "<<z<<" "<<idx<<endl;
		if(ch == 'F' || ch == 'f') {
			if((pos1 >= idx) && (B[pos1] == 1))
				printf("%d = (%.3f,%.3f,%.3f)\n",k,x,y,z);	
			else
				printf("Point doesn't exist in the bucket.\n");
		}
		else {
			if((pos1 >= idx) && (B[pos1] == 1)) {
				if(idx == 0) {
					printf("No more points can be deleted.\n");
				}
				else {
					printf("Point id %d removed.\n",k);
					idx--;
					B[idx] = 1;
					B[pos1] = 0;
				}
			}
			else
				printf("Point doesn't exist in the bucket.\n");
		}
	}
	return 0;
}
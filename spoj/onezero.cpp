#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}
pair<ii,int> nodes[20001];

int main() {
	int t,n,ans[20001],idx,check[20000],pre;
	inp(t);
	while(t--) {
		inp(n);

		nodes[0]=make_pair(ii(1,-1),1);

		queue<int> q;

		if(n==1) {
			printf("1\n");
			continue;
		}

		memset(check,0,sizeof check);
		check[1%n]=1;

		q.push(0);

		pre=1;
		while(!q.empty()) {
			
			int front=q.front();
			q.pop();

			int num=(nodes[front].second*10)%n;

			if(check[num]==0) {
				check[num]=1;
				q.push(pre);
				nodes[pre++]=make_pair(ii(0,front),num);
				if(num==0) {
					pre--;
					break;
				}
			}

			num=(num+1)%n;
			// cout<<num<<" "<<check[num]<<endl;
			if(check[num]==0) {
				check[num]=1;
				q.push(pre);
				nodes[pre++]=make_pair(ii(1,front),num);
				if(num==0) {
					pre--;
					break;
				}
			}
		}

		int cnt=0;

		while(nodes[pre].first.second!=-1){
			ans[cnt++]=nodes[pre].first.first;
			pre=nodes[pre].first.second;

		}

		ans[cnt++]=1;

		char ch='0';

		for(int i=cnt-1;i>=0;i--)
			putchar_unlocked(ch+ans[i]);

		printf("\n");
	}
	return 0;
}
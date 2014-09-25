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

int primes[10000]={0},num;
int A[10000];
queue<ii> q;

void make(int a,int cost) {
	int B[4];

	for(int i=0;i<4;i++) {
		B[i]=a%10;
		a/=10;
	}

	int pro=1;
	int num,num1;
	for(int i=0;i<4;i++,pro*=10) {
		num1=1;
		num=0;
		for(int j=0;j<4;j++,num1*=10) {
			if(j!=i)
				num+=num1*B[j];
		}

		for(int j=0;j<10;j++) {
			if(i==3 && j==0)
				continue;
			num1=num+j*pro;

			// cout<<num1<<endl;
			if(A[num1]==0 && primes[num1]==0) {
				A[num1]=1;
				q.push(ii(num1,cost+1));
			}
		}
	}
}
int main() {
	int t,a,b;

	primes[0]=primes[1]=1;

	for(int i=2;i<=100;i++) {
		if(primes[i]==0) {
			for(int j=i*i;j<10000;j+=i)
				primes[j]=1;
		}
	}

	inp(t);

	while(t--) {
		inp(a);
		inp(b);

		num=0;
		int val=0;
		memset(A,0,sizeof A);

		q.push(ii(a,0));
		ii front;
		A[a]=1;
		while(!q.empty()){
			front=q.front();
			q.pop();
			// cout<<front.first<<" "<<front.second<<endl;
			if(front.first==b) {
				printf("%d\n",front.second);
				val=1;
				break;
			}

			make(front.first,front.second);
		}

		if(val==0)
			printf("Impossible\n");

		while(!q.empty())
			q.pop();

	}

	return 0;
}
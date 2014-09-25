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
#define lli long long int
#define ii pair<long long int,long long int>

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
lli t,a,b,ans,num;
int cnt=0,is_prime[1000001]={0};
lli A[1000001],primes[100000];

bool check(lli num,lli i) {
	int val=1;
	while(num>1){
		if(num%i==0)
			val++;
		else
			return false;
		num/=i;
	}
	if(is_prime[val]==0)
		return true;
	return false;
}

int main() {
	is_prime[0]=1;
	is_prime[1]=1;
	for(int i=2;i<=1000;i++) {
		if(is_prime[i]==0) {
			for(int j=i*i;j<1000001;j+=i)
				is_prime[j]=1;
		}
	}

	for(int i=2;i<1000001;i++)
		if(is_prime[i]==0)
			primes[cnt++]=i;

	inp(t);

	while(t--) {
		inp(a);
		inp(b);
		ans=0;

		memset(A,0,sizeof A);

		for(int i=0;i<cnt;i++) {
			num=a-a%primes[i];
			if(num<a)
				num+=primes[i];
			for(;num<=b;num+=primes[i]) {
				A[num-a]=primes[i];
			}
		}

		for(lli i=max(a,(lli)2);i<=b;i++) {
			if(A[i-a]==0) {
				ans++;
				continue;
			}
			if(check(i,A[i-a]))
				ans++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
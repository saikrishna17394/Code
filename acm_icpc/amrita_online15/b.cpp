#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<long long int,long long int> ii;

using namespace std;

lli powmod(lli n,lli k,lli m) {
	lli ret=1;

	// cout<<n<<" x "<<k<<" "<<m<<endl;
	while(k>0) {
		if(k%2==1) 
			ret=(ret*n)%m;
		n=(n*n)%m;
		k/=2;
	}

	return ret;
}


lli t,n,A[lim]={0};

lli B[lim];

lli dp[101][21];
lli dp1[lim][4];

lli pow2[lim];

int main(){ 
	// cin.sync_with_stdio(false);
	

	for(lli i=2;i*i<=lim;i++) {
		if(A[i]==0) {
			for(lli j=i*i;j<lim;j+=i) {
				A[j]=i;
			}
		}
	}

	pow2[0]=1;
	for(int i=1;i<lim;i++)
		pow2[i]=(2*pow2[i-1])%(mod-1);

	cin>>t;

	while(t--) {
		cin>>n;

		memset(dp,0,sizeof dp);
		memset(dp1,0,sizeof dp1);

		for(lli i=0;i<n;i++) {
			scanf("%lld",&B[i]);

			lli num=B[i];
			

			while(num>1) {
				if(A[num]==0) {
					if(num>100)
						dp1[num][1]++;
					else
						dp[num][1]++;
					break;
				}

				int val=0;
				lli x=A[num];

				while(num%x==0) {
					num/=x;
					val++;
				}
				// cout<<x<<" zz "<<val<<endl;
				if(x>100)
					dp1[x][val]++;
				else
					dp[x][val]++;
			}

		}

		lli ans=1;

		for(lli i=2;i<(lli)101;i++) {
			lli pw=0;
			lli sz=0;

			for(int j=20;j>0;j--) {
				sz+=dp[i][j];
				pw+=pow2[sz];
				pw--;
				
			}

			pw%=(mod-1);

			if(pw<0)
				pw+=(mod-1);
			ans=(ans*powmod(i,pw,mod))%mod;
		}

		for(lli i=101;i<lim;i++) {
			lli pw=0;
			lli sz=0;

			for(int j=3;j>0;j--) {
				sz+=dp1[i][j];
				pw+=pow2[sz];
				pw--;
			}

			pw%=(mod-1);

			if(pw<0)
				pw+=(mod-1);

			ans=(ans*powmod(i,pw,mod))%mod;
		}

		cout<<ans<<endl;
	}	

	return 0;
}
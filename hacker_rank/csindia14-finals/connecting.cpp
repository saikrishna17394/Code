#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;int k;
		cin>>n>>k;
		int p = n/2;
		if(n==1)
			printf("0\n");
		else if(k-2 >= 2)
		{	
			cout<<-1<<endl;
		}
		else
		{
			if(k == 0)
				cout<<0<<endl;
			else if(k == 1)
				cout<<p<<endl;
			else if(k == 2)
			{
				cout<<n<<endl;
			}
			else if( k == 3)
			{
				cout<<(3*n-1)<<endl;
			}
		}

	}
}
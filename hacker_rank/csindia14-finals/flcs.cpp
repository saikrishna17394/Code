#include <bits/stdc++.h>
using namespace std;
int dp[2][100005];
int n,m;
int a[100005],b[100005];
vector<int> bt[2][100005];
int main()
{
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	//j runs from 0 to m
	for (int i = 0; i <= m ; ++i)
	{
		dp[0][i] = 0;
	}
	int index = 1;
	for (int i = 0; i < n; ++i)
	{
		dp[index%2][0] = 0;
		for (int j = 0; j < m; ++j)
		{
			if(a[i] == a[j])
			{
				
			}
		}
	}

}
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int n,s,l;
int A[100000];
int dp[100000];
int tree[400000];

void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx]=inf;
		return;
	}
	int m=(l+r)/2;
	build(2*idx,l,m);
	build(2*idx+1,m+1,r);
	tree[idx]=inf;
	return;
}

void upd(int idx,int l,int r,int x,int val) {
	if(l==r) {
		tree[idx]=val;
		return ;
	}
	int m=(l+r)/2;
	if(x<=m) {
		upd(2*idx,l,m,x,val);
		// tree[idx]
	}
	else
		upd(2*idx+1,m+1,r,x,val);
	tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}

int query(int idx,int l,int r,int i,int j) {
	if(i>j)
		return inf;
	if(l==i && r==j)
		return tree[idx];

	int m=(l+r)/2;

	return min(query(2*idx,l,m,i,min(j,m)),
				query(2*idx+1,m+1,r,max(i,m+1),j));
}

set<ii> S;

int main(){ 
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>s>>l;

	build(1,0,n-1);

	for(int i=0;i<n;i++) {
		// scanf("%d",&A[i]);
		cin>>A[i];
		// cout<<i<<" "<<A[i]<<endl;
	}

	if(l>n) {
		printf("-1\n");
		return 0;
	}

	int a1=A[0],a2=A[0];

	for(int i=0;i<l;i++) {
		a1=max(a1,A[i]);
		a2=min(a2,A[i]);
		// cout<<i<<" "<<a1<<"  w "<<a2<<endl;
		dp[i]=inf;
		S.insert(ii(A[i],i));
	}

	if((a1-a2)>s) {
		printf("-1\n");
		return 0;
	}
	dp[l-1]=1;
	upd(1,0,n-1,l-1,1);

	int idx=0;

	for(int i=l;i<n;i++) {
		a1=max(a1,A[i]);
		a2=min(a2,A[i]);
		// cout<<i<<" "<<a1<<" "<<a2<<" "<<s<<endl;
		if((a1-a2)<=s) {
			dp[i]=1;
			upd(1,0,n-1,i,dp[i]);
			continue;
		}

		int a=S.begin()->first;
		int b=S.rbegin()->first;

		

		if(A[i]<a) {
			while(1) {
				set<ii>::reverse_iterator it=S.rbegin();
				if(it==S.rend())
					break;
				if((it->first-A[i])>s) {
					idx=max(idx,it->second);
					S.erase(*it);
				}
				else
					break;
			}
			idx++;
			S.insert(ii(A[i],i));
		}
		else if(A[i]>b) {
			while(1) {
				set<ii>::iterator it=S.begin();
				if(it==S.end())
					break;
				if((A[i]-it->first)>s) {
					idx=max(idx,it->second);
					S.erase(S.begin());
				}
				else
					break;
			}
			idx++;
			S.insert(ii(A[i],i));
		}
		else
			S.insert(ii(A[i],i));
		
		if(max(idx-1,0)<=(i-l))
			dp[i]=query(1,0,n-1,max(idx-1,0),i-l)+1;
		else
			dp[i]=inf;

		// cout<<i<<" "<<idx<<" "<<S.size()<<endl;
		// cout<<i<<" : "<<dp[i]<<endl;
		upd(1,0,n-1,i,dp[i]);
	}

	cout<<dp[n-1]<<endl;


	return 0;
}
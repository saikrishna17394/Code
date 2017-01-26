#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 200010

using namespace std;

int h,m,n;
vector<int> tree[lim];
ii A[lim];
int vis[lim]={0};
map<int,ii> M;

void upd(int i,int idx,int val) {
	while(idx<tree[i].size()) {
		tree[i][idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int i,int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[i][idx];
		idx-=idx&-idx;
	}
	return sum;
}



int solve(int i,int pos,int id) {
	// cout<<i<<" "<<pos<<" "<<id<<endl;
	// cout<<tree[i].size()<<"-------\n";
	int val=read(i,tree[i].size()-1)-read(i,pos-1);

	if(val<(tree[i].size()-pos)) {
		// printf("man\n");
		int l=pos,r=tree[i].size()-1;
		while(l<r) {
			int mid=(l+r)/2;
			val=read(i,mid)-read(i,pos-1);
			if(val<(mid-pos+1))
				r=mid;
			else
				l=mid+1;
		}
		// cout<<id<<" ** "<<i<<" "<<l<<endl;
		M[id]=ii(i,l);
		upd(i,l,1);
		return (l-pos);
	}
	else {
		int l=1,r=pos-1;

		while(l<r) {
			int mid=(l+r)/2;
			val=read(i,mid);
			if(val<mid)
				r=mid;
			else
				l=mid+1;
		}
		// cout<<id<<" ** "<<i<<" "<<l<<endl;
		M[id]=ii(i,l);
		upd(i,l,1);
		return (tree[i].size()-pos+l-1);
	}
}



int main(){ 
	// cin.sync_with_stdio(false);
	cin>>h>>m>>n;


	int idx=0;

	for(int i=0;i<h;i++) {
		if(vis[i]!=0)
			continue;

		int cur=i;
		tree[idx].push_back(0);
		
		int val=1;

		do {
			vis[cur]=1;
			A[cur]=ii(idx,val);
			// cout<<cur<<" "<<idx<<" "<<val<<endl;
			tree[idx].push_back(0);
			val++;
			cur=(cur+m)%h;
		} while(cur!=i);
		idx++;
	}

	lli ans=0;

	while(n--) {
		char c;
		int id,hash;

		cin>>c;
		// scanf("%c",&c);

		// cout<<c<<endl;
		if(c=='+') {
			// scanf("%d %d",&id,&hash);
			cin>>id>>hash;
			ans+=(lli)solve(A[hash].first,A[hash].second,id);
		}
		else {
			cin>>id;
			// scanf("%d",&id);
			// cout<<id<<" -- "<<M[id].first<<" "<<M[id].second<<endl;
			ii p=M[id];

			upd(p.first,p.second,-1);
			M.erase(id);

		}

		// cout<<id<<" : "<<ans<<endl;

		// for(int i=0;i<idx;i++) {
		// 	for(int j=1;j<tree[i].size();j++) {
		// 		cout<<read(i,j)-read(i,j-1);
		// 	}
		// 	printf("\n");
		// }
		// printf("-------------------\n");


	}	

	cout<<ans<<endl;
	return 0;
}
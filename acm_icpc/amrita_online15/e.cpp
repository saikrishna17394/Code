#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 10010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<long long int,long long int> ii;

using namespace std;


bool cmp(ii a,ii b) {
	a.first/=100;
	b.first/=100;
	return a<b;
}

int t;
int n,m;
lli A[lim];
lli tree[lim],tree1[lim],ans1[lim];
ii q[lim];
vector<ii> B[110];
int pre[lim];

void upd(int idx,lli val) {
	while(idx<lim) {
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

void upd1(int idx,lli val) {
	while(idx<lim) {
		tree1[idx]+=val;
		idx+=(idx&-idx);
	}
}

lli read(int idx) {
	lli sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

lli read1(int idx) {
	lli sum=0;
	while(idx>0) {
		sum+=tree1[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>t;

	while(t--) {
		cin>>n;

		map<lli,lli> M;
		map<ii,int> M1;

		for(int i=1;i<=n;i++) {
			cin>>A[i];
			M[A[i]]=1;
		}

		lli val=0;
		memset(pre,0,sizeof pre);

		for(map<lli,lli>::iterator it=M.begin();it!=M.end();it++)
			it->second=++val;


		cin>>m;

		for(int i=0;i<110;i++)
			B[i].clear();

		for(int i=0;i<m;i++) {
			cin>>q[i].first;
			cin>>q[i].second;
			M1[ii(q[i].second,q[i].first)]=i;
			B[q[i].first/100].push_back(ii(q[i].second,q[i].first));
		}


		lli ans=0;

		for(int i=0;i<110;i++) {
			if(B[i].size()==0)
				continue;
			memset(tree,0,sizeof tree);
			memset(tree1,0,sizeof tree1);


			ii p=B[i][0];

			for(int l=1;l<=p.second;l++) {
				int num=M[A[l]];

				if(pre[num]==0) {
					ans+=A[l]*read1(num);
					upd1(num,1);

					ans+=read(lim-1);
					ans-=read(num);
					upd(num,A[l]);

					ans1[M1[p]]=ans;
					pre[num]=1;
				}
			}

			for(int j=1;j<B[i].size();j++) {
				p=B[i][j];
				ii p1=B[i][j-1];

				if(p.second>p1.second) {
					for(int l=p1.second+1;l<=p.second;l++) {
						int num=M[A[l]];

						if(pre[num]==0) {
							ans+=A[l]*read1(num);
							upd1(num,1);

							ans+=read(lim-1);
							ans-=read(num);
							upd(num,A[l]);

							ans1[M1[p]]=ans;
							pre[num]=1;
						}
						
					}

				}
				else if(p.second<p1.second) {
					for(int l=p.second+1;l<=p.second+1;l++) {
						int num=M[A[l]];

						if(pre[num]==1) {
							ans-=A[l]*read1(num);
							upd1(num,0);

							ans-=read(lim-1);
							ans+=read(num);
							upd(num,-A[l]);

							ans1[M1[p]]=ans;
							pre[num]=0;
						}
						
					}

				}
				else
					;

				for(int l=p1.first+1;l<=p.first;l++) {
					int num=M[A[l]];

					if(pre[num]==0) {
						ans+=A[l]*read1(num);
						upd1(num,1);

						ans+=read(lim-1);
						ans-=read(num);
						upd(num,A[l]);

						ans1[M1[p]]=ans;
						pre[num]=1;
					}

				}
			}

		}

	}	

	return 0;
}
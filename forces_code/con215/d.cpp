#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;

lli n,m,p,ans=0,val;
int A[200001],pat[200001],kmp[200001],num;
map<int,int> hash,hash1,net;
vector<lli> res;

int main() {
	cin>>n>>m>>p;

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	for(int i=0;i<m;i++) {
		scanf("%d",&pat[i]);
		hash[pat[i]]++;
	}


	ans=0;
	res.clear();

	for(lli a=0;a<p;a++) {
		if((a+(m-1)*p)>=n)
			break;
		val=a+(m-1)*p;

		hash1.clear();
		for(lli j=a;j<=val;j+=p) {
			hash1[A[j]]++;
		}
		num=0;


		net=hash;
		map<int,int>::iterator it;
		it=hash1.begin();
		for(;it!=hash1.end();it++) {
			if(net.find(it->first)==net.end())
				net[it->first]=-(it->second);
			else
				net[it->first]-=(it->second);
		}

		for(it=net.begin();it!=net.end();it++)
			if(it->second!=0)
				num++;

		if(num==0)
			res.push_back(a+1);

		for(lli j=a+p,ind=val+p;ind<n;j+=p,ind+=p) {
			if(net[A[j-p]]==0)
				num++;
			net[A[j-p]]++;
			if(net[A[j-p]]==0)
				num--;

			if(net.find(A[ind])==net.end()) {
				num++;
				net[A[ind]]=-1;
			}
			else {
				if(net[A[ind]]==0)
					num++;
				net[A[ind]]--;
				if(net[A[ind]]==0)
					num--;
			}
			if(num==0)
				res.push_back(j+1);
		}

	}

	sort(res.begin(),res.end());
	cout<<(int)res.size()<<endl;

	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	
	return 0;
}
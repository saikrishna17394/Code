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
 
inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar_unlocked(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while( ch >= '0' && ch <= '9' )
    n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

// Solved this problem using BIT ...!! :) :) :)
// Can solve this using segment tree also
// In fact anything solved by BIT can be done by segment tree


int tree[200001]={0},num,hash[200001];
int pre[200001]={0};
pair<char,int> query[200000];
map<int,int> m;
int cnt=1;

void update(int pos,int val) {
	while(pos<cnt) {
		tree[pos]+=val;
		pos+=(pos&-pos);
	}
}

int sum(int pos) {
	int ret=0;
	while(pos) {
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}

int find(int k) {
	// This function is like this because i already checked
	// that kth smallest sum is possible for sure
	// that's why no need to check more conditions
	int l=1,r=cnt-1,mid,val;

	while(l<r) {
		mid=(l+r)/2;

		val=sum(mid);
		//Ikada sachipoyindi oka pichi pani chesi
		// if statement lo
		// if(k>val) {l=mid+1;k-=val;}
		// ani pichi pichi ga cheste ilage jaruguddi
		if(k>val)
			l=mid+1;
		else
			r=mid;
	}
	
	return l;
}

int main() {
	int q;
	char ch;
	inp(q);

	for(int i=0;i<q;i++) {
		ch=getchar_unlocked();
		// cin>>ch;
		inp(num);
		if(ch!='K')
			m[num]=0;
		query[i]=make_pair(ch,num);
	}


	for(map<int,int>::iterator it=m.begin();it!=m.end();it++,cnt++) {
		hash[cnt]=it->first;
		it->second=cnt;
	}
	// cout<<cnt<<endl;
	for(int i=0;i<q;i++) {
		// for(int j=0;j<cnt;j++)
		// 	cout<<tree[j]<<" ";
		// cout<<endl;
		num=query[i].second;
		// cout<<"krish "<<num<<" "<<m[num]<<endl;
		if(query[i].first=='I') {
			if(pre[m[num]]==0) {
				update(m[num],1);
				pre[m[num]]=1;
			}
		}
		else if(query[i].first=='D') {
			if(pre[m[num]]==1) {
				update(m[num],-1);
				pre[m[num]]=0;
			}
		}
		else if(query[i].first=='K') {
			if(num>sum(cnt-1))
				printf("invalid\n");
			else
				printf("%d\n",hash[find(num)] );
		}
		else {
			printf("%d\n",sum(m[num]-1));
		}
	}

	return 0;
}
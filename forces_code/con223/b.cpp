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
typedef pair<int,int> ii;

int n,m,a,b,next[1000010],next1[1000010],mate[1000010];
string s;
int st[1000010],cnt,ans[1000010],pos[1000010],cum[1000010];

int main() {
	cin>>s;
	n=s.length();

	if(s[n-1]=='(')
		next[n-1]=-1;
	else
		next[n-1]=n-1;

	for(int i=n-2;i>=0;i--) {
		if(s[i]=='(')
			next[i]=i;
		else
			next[i]=next[i+1];
	}

	if(s[0]==')')
		next1[0]=0;
	else
		next1[0]=-1;

	for(int i=1;i<n;i++) {
		if(s[i]==')')
			next1[i]=i;
		else
			next1[i]=next1[i-1];
	}

	memset(mate,-1,sizeof mate);
	memset(pos,-1,sizeof pos);

	cnt=0;
	int val=0,cur=0;

	for(int i=0;i<n;i++) {
		if(cnt==0) {
			val=0;
			if(s[i]=='(')
				st[cnt++]=i;
			continue;
		}
		if(s[i]=='(')
			st[cnt++]=i;
		else {
			mate[i]=st[cnt-1];
			mate[st[cnt-1]]=i;
			cnt--;
			val+=2;
			ans[i]=val;
			ans[st[cnt]]=val;
			pos[i]=cur;
			pos[st[cnt]]=cur;
			if(cnt==0) {
				if(cur==0)
					cum[cur]=val;
				else
					cum[cur]=cum[cur-1]+val;
				cur++;
			}
		}
	}
	// cout<<endl;
	// for(int i=0;i<n;i++) {
	// 	cout<<i<<" "<<mate[i]<<" "<<ans[i]<<" "<<pos[i]<<endl;
	// }
	
	scanf("%d",&m);
	while(m--) {
		scanf("%d %d",&a,&b);
		a--;
		b--;
		
		// cout<<next[a]<<" "<<next1[b]<<endl;
		if(next[a]==-1 || next1[b]==-1 || mate[next[a]]==-1 || mate[next1[b]]==-1 ) {
			printf("0\n");
			continue;
		}

		if(next[a]>=b || next1[b]<=a) {
			printf("0\n");
			continue;
		}

		val=0;
		int l=pos[next[a]],r=pos[next1[b]];

		if(l==r) {
			if(mate[next[a]]<=b)
				val=ans[next[a]];
			if(mate[next1[b]]>=a)
				val=ans[next1[b]];
		}
		else {
			val+=ans[next[a]];
			val+=ans[next1[b]];
			l++;
			r--;
			if(l<=r) {
				val+=cum[r];
				if(l>0)
					val-=cum[l-1];
			}
		}
		printf("%d\n", val);
	}

	return 0;
}
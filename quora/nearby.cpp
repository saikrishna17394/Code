#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

double dist(double x,double y) 
{
	return x*x+y*y;
}

struct entry 
{
	double d;
	int id;
	bool operator<(const entry& a) const 
	{
		if(abs(d-a.d)<1e-6) {
			return id>a.id;
		}
		return d<a.d;
	}
};



int main() 
{
	int t,q,n,id,qn,num,results;
	char ch;
	double x,y,x1,y1;
	int topics[10000],questions[1000];
	vector<int> related_topics[100001];
	pair<double,double> topic_location[100001];
	double topic_dist[100001];

	scanf("%d %d %d",&t,&q,&n);

	for(int i=0;i<t;i++) 
	{
		scanf("%d",&id);
		cin>>x>>y;
		topics[i]=id;
		topic_location[id]=make_pair(x,y);
	}

	int cnt=0;
	for(int i=0;i<q;i++) 
	{
		scanf("%d %d",&id,&qn);
		if(qn)
		{
			questions[cnt++]=id;
			for(int j=0;j<qn;j++) 
			{
				scanf("%d",&num);
				related_topics[id].push_back(num);
			}
		}
	}
	q=cnt;

	while(n--) 
	{
		cin>>ch;
		scanf("%d",&results);
		cin>>x>>y;
		
		set<entry> s;
		if(ch=='t') 
		{
			for(int i=0;i<t;i++)
			{
				entry e;
				e.id=topics[i];
				x1=topic_location[e.id].first;
				y1=topic_location[e.id].second;
				e.d=dist(x-x1,y-y1);
				s.insert(e);
				
				if(s.size()>results) {
					set<entry>::iterator it=s.end();
					it--;
					s.erase(it);
				}
			}

			set<entry>::iterator it=s.begin();
			results=min(results,(int)s.size());
			while(results--) 
			{
				// if(it==s.end())
				// 	break;
				printf("%d ",it->id);
				it++;
			}
			printf("\n");
		}
		else 
		{
			for(int i=0;i<t;i++)
			{
				x1=topic_location[topics[i]].first;
				y1=topic_location[topics[i]].second;
				topic_dist[topics[i]]=dist(x-x1,y-y1);
			}

			for(int i=0;i<q;i++)
			{
				entry e;
				e.id=questions[i];

				e.d=1e15; // 1e15 can be treated as infinity in this problem
				for(int j=0;j<related_topics[e.id].size();j++) 
				{
					e.d=min(e.d,topic_dist[related_topics[e.id][j]]);
				}
				s.insert(e);

				if(s.size()>results) {
					set<entry>::iterator it=s.end();
					it--;
					s.erase(it);
				}
			}

			set<entry>::iterator it=s.begin();
			results=min(results,(int)s.size());
			while(results--) 
			{
				// if(it==s.end())
				// 	break;
				printf("%d ",it->id);
				it++;
			}
			printf("\n");
		}
	}

	return 0;
}
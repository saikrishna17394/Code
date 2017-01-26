#include <bits/stdc++.h>
#include <sstream>

#define ii pair<int,int>

using namespace std;

map<string,int> m;

vector<string> sent[500000];
vector<int> sent_id[500000];
int A[500000];

int main() {
	int l,th;
	int g,n;
	cin>>l>>th;
	cin>>g>>n;

	for(int i=0;i<n;i++) {
		int id;
		scanf("%d-",&A[i]);
		string s;
		getline(cin,s);
		stringstream ss(s);
		

		while(ss>>s) {
			sent[i].push_back(s);
			m[s]=1;
		}
		// cout<<s<<endl;
	}

	int idx=0;
	map<int,string> m2;

	for(map<string,int>::iterator it=m.begin();it!=m.end();it++) {
		it->second=idx++;
		m2[idx-1]=it->first;
	}

	map<vector<int>,vector<ii> > m1;

	for(int i=0;i<n;i++) {
		for(int j=0;j<sent[i].size();j++) {
			sent_id[i].push_back(m[sent[i][j]]);
		}

		vector<int> v;
		for(int k=0;(k+l)<=sent_id[i].size();k++) {
			vector<int> v;
			for(int j=0;j<l;j++) {
				v.push_back(sent_id[i][k+j]);
			}
			m1[v].push_back(ii(A[i],k));
		}
	}

	for(map<vector<int>,vector<ii> >::iterator it=m1.begin();it!=m1.end();it++) {
		// cout<<it->second.size()<<endl;

		if(it->second.size()>=th) {
			for(int i=0;i<it->first.size();i++) {
				cout<<m2[(it->first)[i]]<<" ";
			}
			printf(" : ");
			
			for(int i=0;i<it->second.size();i++) {
				printf("(" );
				printf("%d,",(it->second)[i].first );
				printf("%d,", (it->second)[i].second);
				printf("%d", (it->second)[i].second+l-1);
				printf(") ");
			}
			printf("\n");
		}
	}
	return 0;
}
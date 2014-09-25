#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> ii;

int main() {
	int n,A[100000],ind=0,num,len;
	set<ii> s;
	vector<int> v,v1;

	scanf("%d",&n);

	while(n--) {
		scanf("%d",&num);
		if(num==0) {
			len=v.size();
			ind=0;

			if(len==0) {
				printf("0\n");
			}
			else if(len==1) {
				printf("pushStack\n");
				printf("1 popStack\n");
			}
			else if(len==2) {
				printf("pushStack\n");
				printf("pushQueue\n");
				printf("2 popStack popQueue\n");
			}
			else {
				v1.clear();
				set<ii>::reverse_iterator it=s.rbegin();
				v1.push_back(it->second);
				it++;
				v1.push_back(it->second);
				it++;
				v1.push_back(it->second);
				sort(v1.begin(),v1.end());

				for(int i=0;i<len;i++) {
					if(i<v1[0]) {
						printf("pushStack\n");
					}
					else if(i==v1[0]) {
						printf("pushQueue\n");
					}
					else if(i<=v1[1]) {
						printf("pushStack\n");
					}
					else if(i==v1[2]){
						printf("pushFront\n");
					}
					else {
						printf("pushBack\n");
					}
				}
				printf("3 popStack popQueue popFront\n");
			}
			s.clear();
			v.clear();
		}
		else{
			s.insert(ii(num,ind));
			ind++;
			v.push_back(num);
		}
	}

	len=v.size();
	for(int i=0;i<len;i++)
		printf("pushStack\n");
	
	return 0;
}
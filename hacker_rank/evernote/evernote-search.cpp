#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct note {
	string guid;
	string created;
	vector<string> tags;
	string content;
};

note A[10000];
int avail[10000000],idx=0,cnt=10000;
map<string,int> m;

void create();
void print(int);

int main() {
	for(int i=0;i<cnt;i++)
		avail[i]=i;
	
	string s;
	while(1) {
		cin>>s;
		if(s=="CREATE") {
			int num=avail[idx];
			create();
			print(num);
		}
		else if(s=="UPDATE") {

		}
		else if(s=="DELETE") {

		}
		else if(s=="SEARCH") {

		}
		else
			;
	}
    return 0;
}

void create() {
	string s;
	int key;

	cin>>s;
	if(s!="<note>")
		perror("Incorrect syntax\n");

	if(cnt>0) {
		key=avail[idx++];
		cnt--;
	}
	else
		perror("Insufficient memory\n");

	// guid
	cin>>s;
	s=s.substr(6,s.length()-13);
	A[key].guid=s;
	m[s]=key;

	// created
	cin>>s;
	s=s.substr(9,s.length()-19);
	A[key].created=s;

	A[key].tags.clear();
	while(1) {
		cin>>s;
		if(s.substr(0,5)!="<tag>")
			break;
		A[key].tags.push_back(s.substr(5,s.length()-11));
	}

	while(s!="<content>")
		cin>>s;

	A[key].content="";
	while(1) {
		cin>>s;
		if(s=="</content>")
			break;
		A[key].content+=s+" ";
	}

	cin>>s;
	if(s!="</note>")
		perror("Incorrect syntax\n");

}

void print(int i) {
	cout<<"guid : "<<A[i].guid<<endl;
	cout<<"created : "<<A[i].created<<endl;
	
	cout<<"tags : ";
	for(int j=0;j<A[i].tags.size();j++)
		cout<<A[i].tags[j]<<",";
	cout<<endl;

	cout<<"content :\n";
	cout<<A[i].content<<endl;
}
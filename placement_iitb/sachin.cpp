#include <iostream>

using namespace std;

int main() {
	string s[9];

	for(int i=0;i<9;i++)
		cin>>s[i];

	int B[9]={0,1,2,5,8,7,6,3,4};

	for(int i=0;i<9;i++)
		cout<<s[B[i]]<<" ";
	cout<<endl;

	return 0;
}
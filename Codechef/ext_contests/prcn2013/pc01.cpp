#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int t;
	bool val;
	inp(t);
	string s[5],str;
	while(t--) {

		for(int i=0;i<5;i++) {
		 	getline(cin,s[i]);
		 	//cout<<s[i]<<endl;
		 }
		int myints[]={1,2,3,4,5};

		do {
			val=true;
			for(int i=0;i<5;i++) {
				int k=s[i].length();
				for(int j=0;j<k;j++) {
					str="";
					if(j+1==k || s[i][j+1]==' ') {
						str+=s[i][j];
						//cout<<str<<endl;
						j++;
					}
					else {
						str+=s[i][j];
						str+=s[i][j+1];
						j+=2;
						//cout<<str<<endl;
					}
					if(str.length()==1) {
						if(str[0]>='1' && str[0]<='5') {
							if(str[0]!=myints[i]+'0')
								val=false;
						}
						else {
							if(abs(myints[i]-myints[str[0]-'A'])!=1)
								val=false;
						}

					}
					else {
						if(str[0]=='N') {
							if(str[1]>='1' && str[1]<='5') {
								if(str[1]==myints[i]+'0')
									val=false;
							}
							else {
								if(abs(myints[i]-myints[str[1]-'A'])==1)
									val=false;
							}

						}
						else if (str[0]=='+'){
							if(myints[i]<=myints[str[1]-'A'])
								val=false;
						}
						else {
							if(myints[i]>=myints[str[1]-'A'])
								val=false;

						}

					}
					if(val==false)
						break;

				}
				if(val==false)
					break;
			}
			if(val==true)
			 break;
		}	while(next_permutation(myints,myints+5));

		string krish="     ";
		for(int i=0;i<5;i++)
			krish[myints[i]-1]='A'+i;
		cout<<krish<<endl;
	}
	return 0;
}
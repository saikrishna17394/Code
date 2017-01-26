// BEGIN CUT HERE

// END CUT HERE
#line 5 "BoardFolding.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
using namespace std;

int A[270][270];
int r[250],c[250];
int B[250][250][250];
int dp[250][250];

class BoardFolding {
    public:
    int to_n (char c) {
		if(c>='0' && c<='9')
			return c-'0';
		if(c>='a' && c<='z')
			return c-'a'+10;
		if(c>='A' && c<='Z')
			return c-'A'+36;
		if(c=='#')
			return 62;
		return 63;   	
    }
    int n,m;

    void pre() {
    	int idx=0;
    	map<vector<int>,int> s;

		for(int i=0;i<n;i++) {
			vector<int> v;
			for(int j=0;j<9;j++) {
				int num=0;
				for(int k=0;k<30;k++)
					num=num*2+A[i][30*j+k];
				v.push_back(num);
			}
			if(s.find(v)==s.end()) {
				s[v]=idx;
				r[i]=idx++;
			}
			else
				r[i]=s[v];
		}

		idx=0;
		s.clear();

		for(int i=0;i<m;i++) {
			vector<int> v;
			for(int j=0;j<9;j++) {
				int num=0;
				for(int k=0;k<30;k++)
					num=num*2+A[30*j+k][i];
				v.push_back(num);
			}
			if(s.find(v)==s.end()) {
				s[v]=idx;
				c[i]=idx++;
			}
			else
				c[i]=s[v];
		}		
    }

    int howMany(int N, int M, vector <string> v) {
         //$CARETPOSITION$
    	n=N;
    	m=M;
    	memset(A,0,sizeof A);
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    			A[i][j]=(to_n(v[i][j/6])>>(j%6))%2;
    
    	cout<<n<<" "<<m<<endl;
    	pre();
    	for(int i=0;i<n;i++)
    		printf("%d ",r[i] );
    	// printf("what\n");
    	printf("\n");
    	for(int j=0;j<m;j++)
    		printf("%d ",c[j] );
    	printf("\n");
    	return 0;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BoardFolding ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 

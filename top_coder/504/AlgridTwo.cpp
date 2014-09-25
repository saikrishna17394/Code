// BEGIN CUT HERE

// END CUT HERE
#line 5 "AlgridTwo.cpp"
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


class AlgridTwo {
    public:
    int makeProgram(vector <string> s) {
         //$CARETPOSITION$
    	int n=s.size();
    	int m=s[0].size(),A[50][50];

    	memset(A,-1,sizeof A);
    	int ans=1;

    	for(int i=0;i<(n-1);i++) {
    		for(int j=0;j<(m-1);j++) {
    			char a=s[i][j];
    			char b=s[i][j+1];

    			if(a=='W' && b=='W')
    				;
    			else if(a=='B' && b=='W') {
    				A[i+1][j]='B';
    				A[i+1][j+1]='B';
    			}
    			else if(a=='W' && b=='B') {
    				A[i+1][j]='W';
    				A[i+1][j+1]='W';
    			}
    			else {
    				swap(A[i+1][j],A[i+1][j+1]);
    			}

    		}
    		for(int j=0;j<m;j++) {
    			if(A[i+1][j]!=-1) {
    				if(A[i+1][j]==s[i+1][j])
	    				ans=(ans*2)%mod;
	    			else
	    				ans=0;
    			}
    		}
    	}

    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BB",
 "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, makeProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBWBBB",
 "WBWBBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, makeProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"BWBWBW",
 "WWWWWW",
 "WBBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, makeProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBB",
 "BWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(3, Arg1, makeProgram(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AlgridTwo ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 

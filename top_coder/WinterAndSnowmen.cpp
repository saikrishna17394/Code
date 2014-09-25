// BEGIN CUT HERE

// END CUT HERE
#line 5 "WinterAndSnowmen.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#define mod 1000000007
using namespace std;

int n,m,dp[2001][2048][2048];

class WinterAndSnowmen {
    public:
    int solve(int i,int m1,int m2) {
    	if(i>n && i>m) {
    		if(m1<m2)
	    		return 1;
	    	return 0;
    	}
    	int &ret=dp[i][m1][m2];
    	if(ret!=-1)
    		return ret;

    	ret=solve(i+1,m1,m2);
    	if(i<=n)
	    	ret=(ret+solve(i+1,m1^i,m2))%mod;
	    if(i<=m)
	    	ret=(ret+solve(i+1,m1,m2^i))%mod;
	    return ret;
    }

    int getNumber(int N, int M) {
         //$CARETPOSITION$
    	n=N;
    	m=M;
    	memset(dp,-1,sizeof dp);
    	return solve(1,0,0);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 74; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 216; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 962557390; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     WinterAndSnowmen ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

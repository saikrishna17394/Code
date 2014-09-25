// BEGIN CUT HERE

// END CUT HERE
#line 5 "EventOrder.cpp"
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
int dp[1001][1001];
int dp1[2001];

class EventOrder {
    public:
    int solve(int l,int r) {
    	if(l+r==0)
    		return 1;
    	int& ret=dp[l][r];
    	if(ret!=-1)
    		return ret;


    }

    int solve1(int l,int r) {

    }
    
    int getCount(int longEvents, int instantEvents) {
         //$CARETPOSITION$
    	memset(dp,-1,sizeof dp);
    	return solve(longEvents,instantEvents);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 5; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 13; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 4; int Arg2 = 75; verify_case(3, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     EventOrder ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

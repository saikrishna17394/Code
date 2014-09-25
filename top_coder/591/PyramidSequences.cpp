// BEGIN CUT HERE

// END CUT HERE
#line 5 "PyramidSequences.cpp"
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
#define lli long long int
using namespace std;

class PyramidSequences {
    public:
    long long distinctPairs(int n, int m) {
         //$CARETPOSITION$
    	long long ans=0;

    	if(n==m)
    		ans=m;
    	else {
    		if(n>m)
    			swap(n,m);

    		lli x,y;

    		x=2*n-2;
    		y=2*m-2;

    		

    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; long long Arg2 = 6LL; verify_case(0, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; long long Arg2 = 5LL; verify_case(1, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 43; int Arg1 = 76; long long Arg2 = 895LL; verify_case(2, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 1000000000; long long Arg2 = 1000000000LL; verify_case(3, Arg2, distinctPairs(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 95555; long long Arg2 = 4777750000LL; verify_case(4, Arg2, distinctPairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     PyramidSequences ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

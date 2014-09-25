// BEGIN CUT HERE

// END CUT HERE
#line 5 "NumbersAndMatches.cpp"
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

using namespace std;

class NumbersAndMatches {
    public:
    long long differentNumbers(long long N, int K) {
         //$CARETPOSITION$
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(0, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 23LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(1, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 66LL; int Arg1 = 2; long long Arg2 = 15LL; verify_case(2, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 888888888LL; int Arg1 = 100; long long Arg2 = 1LL; verify_case(3, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 444444444444444444LL; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, differentNumbers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     NumbersAndMatches ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

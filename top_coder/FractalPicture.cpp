// BEGIN CUT HERE

// END CUT HERE
#line 5 "FractalPicture.cpp"
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

class FractalPicture {
    public:
    double getLength(int x1, int y1, int x2, int y2) {
         //$CARETPOSITION$
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = -1; int Arg1 = 0; int Arg2 = 1; int Arg3 = 53; double Arg4 = 53.0; verify_case(0, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; double Arg4 = 0.0; verify_case(1, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = -10; int Arg1 = 54; int Arg2 = 10; int Arg3 = 55; double Arg4 = 21.0; verify_case(2, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 45; int Arg2 = 22; int Arg3 = 54; double Arg4 = 2999.0; verify_case(3, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FractalPicture ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 

// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndFencing.cpp"
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

class FoxAndFencing {
    public:
    string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
         //$CARETPOSITION$
    	if(rng1>=d-mov1 || (mov1>mov2 && mov1+rng1>=2*mov2+rng2+1))
    		return "Ciel";
    	if(rng2+mov2>=mov1+d || (mov2>mov1 && mov2+rng2>=2*mov1+rng1+1))
    		return "Liss";
    	return "Draw";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 1; int Arg3 = 58; int Arg4 = 2; string Arg5 = "Ciel"; verify_case(0, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 100; int Arg4 = 50; string Arg5 = "Liss"; verify_case(1, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 100; int Arg4 = 150; string Arg5 = "Draw"; verify_case(2, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 100; int Arg3 = 100; int Arg4 = 100000000; string Arg5 = "Draw"; verify_case(3, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 100; int Arg3 = 1; int Arg4 = 100000000; string Arg5 = "Ciel"; verify_case(4, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 100; int Arg3 = 250; int Arg4 = 100000000; string Arg5 = "Draw"; verify_case(5, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 100; int Arg3 = 150; int Arg4 = 100000000; string Arg5 = "Ciel"; verify_case(6, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { int Arg0 = 100; int Arg1 = 50; int Arg2 = 100; int Arg3 = 1; int Arg4 = 100000000; string Arg5 = "Ciel"; verify_case(7, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_8() { int Arg0 = 100; int Arg1 = 150; int Arg2 = 100; int Arg3 = 1; int Arg4 = 100000000; string Arg5 = "Draw"; verify_case(8, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     FoxAndFencing ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

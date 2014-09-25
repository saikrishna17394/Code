// BEGIN CUT HERE

// END CUT HERE
#line 5 "AllCycleLengths.cpp"
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

class AllCycleLengths {
      public:
      string findAll(vector <string> arcs) {
            //$CARETPOSITION$
      }
      
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN", "NNYY", "NNNY", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "00110(1)"; verify_case(0, Arg1, findAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"NY", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(01)"; verify_case(1, Arg1, findAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0(1)"; verify_case(2, Arg1, findAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010(1)"; verify_case(3, Arg1, findAll(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     AllCycleLengths ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

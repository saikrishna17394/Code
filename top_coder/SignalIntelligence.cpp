// BEGIN CUT HERE

// END CUT HERE
#line 5 "SignalIntelligence.cpp"
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

class SignalIntelligence {
    public:
    long long encrypt(vector <int> numbers) {
         //$CARETPOSITION$
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(0, Arg1, encrypt(Arg0)); }
	void test_case_1() { int Arr0[] = {4,4,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 19LL; verify_case(1, Arg1, encrypt(Arg0)); }
	void test_case_2() { int Arr0[] = {1000000000,1000000000,1000000000,1000000000,1000000000,
1000000000,1000000000,1000000000,1000000000,1000000000,
1000000000,1000000000,1000000000,1000000000,1000000000,
1000000000,1000000000,1000000000,1000000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 281475976710655LL; verify_case(2, Arg1, encrypt(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SignalIntelligence ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 

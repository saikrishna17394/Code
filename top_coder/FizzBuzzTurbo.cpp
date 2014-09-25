// BEGIN CUT HERE

// END CUT HERE
#line 5 "FizzBuzzTurbo.cpp"
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

class FizzBuzzTurbo {
    public:
    vector<long long> counts(long long A, long long B) {
         //$CARETPOSITION$
    	vector<long long> v;
    	long long a;
    	a=(A-1)/3;
    	a=B/3-a;
    	v.push_back(a);

    	a=(A-1)/5;
    	a=B/5-a;
    	v.push_back(a);

    	a=(A-1)/15;
    	a=B/15-a;
    	v.push_back(a);

    	v[0]-=v[2];
    	v[1]-=v[2];

    	return v;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 4LL; long Arr2[] = {1, 0, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, counts(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 2LL; long long Arg1 = 6LL; long Arr2[] = {2, 1, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, counts(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 150LL; long long Arg1 = 165LL; long Arr2[] = {4, 2, 2 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, counts(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 474747LL; long long Arg1 = 747474LL; long Arr2[] = {72728, 36363, 18182 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, counts(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FizzBuzzTurbo ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 

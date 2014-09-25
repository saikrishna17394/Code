// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomSort.cpp"
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

class RandomSort {
    public:
    map<vector<int>,double> memo;

    double getExpected(vector <int> permutation) {
        //$CARETPOSITION$
     	if(memo.find(permutation)!=memo.end())
     		return memo[permutation];
     	double & res=memo[permutation];

     	res=0;
     	int tot=0;
     	for(int i=0;i<permutation.size();i++) {
     		for(int j=i+1;j<permutation.size();j++) {
     			if(permutation[i]>permutation[j]) {
     				swap(permutation[i],permutation[j]);
     				res+=1+getExpected(permutation);
     				swap(permutation[i],permutation[j]);
     				tot++;
     			}
     		}
     	}

     	if(tot!=0)
     		res=res/tot;
     	return res;
    }
 
     
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.066666666666666; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,1,6,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.666666666666666; verify_case(3, Arg1, getExpected(Arg0)); }

// END CUT HERE

 };

    // BEGIN CUT HERE
int main() {
     RandomSort ___test;
      ___test.run_test(-1);
      system("pause");
}
    // END CUT HERE 

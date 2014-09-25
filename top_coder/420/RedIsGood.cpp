// BEGIN CUT HERE

// END CUT HERE
#line 5 "RedIsGood.cpp"
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

double dp[2][5001];

class RedIsGood {
    public:

    double getProfit(int R, int B) {
         //$CARETPOSITION$
    	for(int j=0;j<=B;j++)
    		dp[0][j]=0;
    	for(int i=1;i<=R;i++) {
    		dp[1][0]=(double)i;
    		for(int j=1;j<=B;j++) {
    			double val=(double)i;
				val/=(double)(i+j);
				dp[1][j]=0;
				dp[1][j]=max(dp[1][j],val*(1+dp[0][j])+(1.0-val)*(dp[1][j-1]-1));
    		}
    		for(int j=0;j<=B;j++)
    			dp[0][j]=dp[1][j];
       
    	}
    	return dp[0][B];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 7; double Arg2 = 0.0; verify_case(0, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 0; double Arg2 = 4.0; verify_case(1, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; double Arg2 = 4.166666666666667; verify_case(2, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.6666666666666666; verify_case(3, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; int Arg1 = 4; double Arg2 = 8.324175824175823; verify_case(4, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 12; double Arg2 = 1.075642825339958; verify_case(5, Arg2, getProfit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     RedIsGood ___test;
      ___test.run_test(-1);
      // ___test.test_case_3();
      system("pause");
}
// END CUT HERE 

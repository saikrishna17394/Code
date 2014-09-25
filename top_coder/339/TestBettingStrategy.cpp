// BEGIN CUT HERE

// END CUT HERE
#line 5 "TestBettingStrategy.cpp"
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
#define eps 1e-9
using namespace std;

double dp[1001][51][11];

class TestBettingStrategy {
    public:
    double a;
    int goal;

    double ans(int init,int k,int losses) {
    	// cout<<init<<" "<<goal<<" "<<k<<" "<<losses<<" xx"<<endl;
    	if(init==goal)
    		return 1;
    	if(k==0)
    		return 0;
		int num=(1<<losses);

		if(init<num)
			return 0;
    	if((dp[init][k][losses]+1)>eps)
    		return dp[init][k][losses];

    	double val=0;

    	

    	val=a*ans(init+num,k-1,0);
		// cout<<init<<" "<<goal<<" "<<k<<" "<<losses<<" "<<val<<endl;

		val+=(1-a)*ans(init-num,k-1,losses+1);

    	dp[init][k][losses]=val;

    	// cout<<init<<" "<<goal<<" "<<k<<" "<<losses<<" "<<val<<endl;

    	return val;
    }
    double winProbability(int initSum, int goalSum, int rounds, int prob) {
         //$CARETPOSITION$
    	a=(double)prob/100.0;
    	goal=goalSum;
    	memset(dp,-1,sizeof dp);

    	return ans(initSum,rounds,0);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	// private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 4; int Arg3 = 50; double Arg4 = 0.875; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 20; int Arg3 = 50; double Arg4 = 0.3441343307495117; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 10; int Arg3 = 90; double Arg4 = 0.34867844010000015; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 24; int Arg1 = 38; int Arg2 = 24; int Arg3 = 60; double Arg4 = 0.5940784635646947; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     TestBettingStrategy ___test;
     // ___test.ans(9,11,3,1);
      ___test.run_test(-1);
     // ___test.test_case_0();
      system("pause");
}
// END CUT HERE 

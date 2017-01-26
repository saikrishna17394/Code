// BEGIN CUT HERE

// END CUT HERE
#line 5 "RepeatString.cpp"
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


int dp[50][50][50][50];
class RepeatString {
    public:
    string s1;
    int n;

    int solve(int a,int b,int c,int d) {
    	if(a>b)
    		return max(0,(d-c)+1);
    	if(c>d)
    		return max(0,(b-a)+1);
    	int& ret = dp[a][b][c][d];
    	if(ret!=-1)
    		return ret;

    	if(s[a] == s[c])
    		ret = solve(a+1,b,c+1,d);
    	else {

    	}
    }

    int minimalModify(string s) {
         //$CARETPOSITION$
    	memset(dp,-1,sizeof dp);
    	s1 = s;
    	n = s.length();
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 1; verify_case(0, Arg1, minimalModify(Arg0)); }
	void test_case_1() { string Arg0 = "adam"; int Arg1 = 1; verify_case(1, Arg1, minimalModify(Arg0)); }
	void test_case_2() { string Arg0 = "x"; int Arg1 = 1; verify_case(2, Arg1, minimalModify(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbbaaaccc"; int Arg1 = 3; verify_case(3, Arg1, minimalModify(Arg0)); }
	void test_case_4() { string Arg0 = "repeatstring"; int Arg1 = 6; verify_case(4, Arg1, minimalModify(Arg0)); }
	void test_case_5() { string Arg0 = "aaaaaaaaaaaaaaaaaaaa"; int Arg1 = 0; verify_case(5, Arg1, minimalModify(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RepeatString ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 

// BEGIN CUT HERE

// END CUT HERE
#line 5 "NewArenaPassword.cpp"
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

class NewArenaPassword {
    public:
    int minChange(string s, int k) {
         //$CARETPOSITION$
    	int len=s.length();
    	if(len==k)
    		return 0;
    	int ans=0;
    	int A[26];
    	for(int i=0;i<(len-k);i++) {
    		memset(A,0,sizeof A);
    		int val=0;
    		for(int j=i;j<len;j+=(len-k)) {
    			A[s[j]-'a']++;
    			val++;
    		}
    		sort(A,A+26);
    		ans+=(val-A[25]);
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoderopen"; int Arg1 = 5; int Arg2 = 3; verify_case(0, Arg2, minChange(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "puyopuyo"; int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, minChange(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "loool"; int Arg1 = 3; int Arg2 = 1; verify_case(2, Arg2, minChange(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "arena"; int Arg1 = 5; int Arg2 = 0; verify_case(3, Arg2, minChange(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "amavckdkz"; int Arg1 = 7; int Arg2 = 5; verify_case(4, Arg2, minChange(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     NewArenaPassword ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

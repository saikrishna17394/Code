// BEGIN CUT HERE

// END CUT HERE
#line 5 "PenguinPals.cpp"
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

class PenguinPals {
    public:
    int findMaximumMatching(string s) {
         //$CARETPOSITION$
    	int len=s.length();
    	// cout<<s<<" "<<len<<endl;
    	if(len<=1)
    		return 0;

    	string s1="";
    	int idx=-1;
    	for(int i=0;i<len;i++) {
    		if(s[i]==s[(i+1)%len]) {
    			idx=i;
    			break;
    		}
    	}

    	if(idx>=0) {
    		for(int i=0;i<len;i++) {
    			if(i==idx || (idx+1)%len==i)
    				continue;
    			s1+=s[i];
    		}
    		return 1+findMaximumMatching(s1);
    	}

    	if(len==2)
    		return 0;
    	
    	s1="";
    	for(int i=0;i<len;i++) {
    		if(s[i]==s[(i+2)%len]) {
    			idx=i;
    			break;
    		}
    	}

		for(int i=0;i<len;i++) {
			if(i==idx || (idx+2)%len==i || (idx+1)%len==i)
				continue;
			s1+=s[i];
		}
		return 1+findMaximumMatching(s1);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRBRBRBB"; int Arg1 = 3; verify_case(0, Arg1, findMaximumMatching(Arg0)); }
	void test_case_1() { string Arg0 = "RRRR"; int Arg1 = 2; verify_case(1, Arg1, findMaximumMatching(Arg0)); }
	void test_case_2() { string Arg0 = "BBBBB"; int Arg1 = 2; verify_case(2, Arg1, findMaximumMatching(Arg0)); }
	void test_case_3() { string Arg0 = "RBRBRBRBR"; int Arg1 = 4; verify_case(3, Arg1, findMaximumMatching(Arg0)); }
	void test_case_4() { string Arg0 = "RRRBRBRBRBRB"; int Arg1 = 5; verify_case(4, Arg1, findMaximumMatching(Arg0)); }
	void test_case_5() { string Arg0 = "R"; int Arg1 = 0; verify_case(5, Arg1, findMaximumMatching(Arg0)); }
	void test_case_6() { string Arg0 = "RBRRBBRB"; int Arg1 = 3; verify_case(6, Arg1, findMaximumMatching(Arg0)); }
	void test_case_7() { string Arg0 = "RBRBBRBRB"; int Arg1 = 4; verify_case(7, Arg1, findMaximumMatching(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     PenguinPals ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

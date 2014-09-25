// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndString.cpp"
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

class LittleElephantAndString {
    public:
    int A[26];

    int ans(string a,string b) {
    	if(a==b)
    		return 0;
    	int ch=b[0];
    	int len=a.length(),ret=99999999;
    	b.erase(b.begin());
    	
    	string s1=a,s2="";

    	for(int i=0;i<len;i++) {
    		s1.erase(s1.begin());
    		if(a[i]==ch) {
    			ret=min(ret,1+ans(s2+s1,b));
    		}
    		s2+=a[i];
    	}
    	return ret;
    }
    
    int getNumber(string a, string b) {
         //$CARETPOSITION$
    	int len=a.length();
    	memset(A,0,sizeof A);
    	for(int i=0;i<len;i++) {
    		A[a[i]-'A']++;
    		A[b[i]-'A']--;
    	}
    	for(int i=0;i<26;i++) {
    		if(A[i]!=0)
    			return -1;
    	}
    	return ans(a,b);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABC"; string Arg1 = "CBA"; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "A"; string Arg1 = "B"; int Arg2 = -1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAABBB"; string Arg1 = "BBBAAA"; int Arg2 = 3; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string Arg1 = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; int Arg2 = 25; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "A"; string Arg1 = "A"; int Arg2 = 0; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "DCABA"; string Arg1 = "DACBA"; int Arg2 = 2; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     LittleElephantAndString ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

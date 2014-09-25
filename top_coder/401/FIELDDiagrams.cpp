// BEGIN CUT HERE

// END CUT HERE
#line 5 "FIELDDiagrams.cpp"
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
#define lli long long int
using namespace std;

class FIELDDiagrams {
    public:
    lli A[31][31];
    long long countDiagrams(int fieldOrder) {
         //$CARETPOSITION$
    	memset(A,0,sizeof A);
    	lli ans=0;

    	A[fieldOrder][1]=1;

    	for(int i=fieldOrder-1;i>0;i--) {
    		A[i][1]=A[i+1][1]+1;
    	}

    	for(int j=2;j<=fieldOrder;j++) {
    		A[fieldOrder-j+1][j]=A[fieldOrder-j+1][j-1];
    		for(int i=fieldOrder-j;i>0;i--) {
    			A[i][j]=A[i+1][j]+A[i][j-1];
    		}
    	}

    	for(int i=1;i<=fieldOrder;i++)
    		ans+=A[1][i];
    	// cout<<A[1][1]<<" "<<A[2][1]<<endl;
    	// cout<<A[1][2]<<endl;
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; verify_case(0, Arg1, countDiagrams(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 13LL; verify_case(1, Arg1, countDiagrams(Arg0)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 131LL; verify_case(2, Arg1, countDiagrams(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     FIELDDiagrams ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

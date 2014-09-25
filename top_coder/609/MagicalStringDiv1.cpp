// BEGIN CUT HERE

// END CUT HERE
#line 5 "MagicalStringDiv1.cpp"
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

class MagicalStringDiv1 {
    public:
    int A[50],B[50];
    int getLongest(string s) {
         //$CARETPOSITION$
    	int len=s.length();
    	int ans=len;
    	memset(A,0,sizeof A);
    	memset(B,0,sizeof B);

    	int a=0,b=0;
    	for(int i=0;i<len;i++) {
    		if(s[i]=='<')
    			a++;
    		else
    			b++;
    		A[i]=a;
    		B[i]=b;
    	}
    	ans=0;
    	for(int i=0;i<len;i++) {
    		int val=min(B[i],a-A[i]);
    		ans=max(ans,2*val);
    		// cout<<i<<" "<<val<<" "<<ans<<endl;
    	}
    	return ans;

    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "<><><<>"; int Arg1 = 4; verify_case(0, Arg1, getLongest(Arg0)); }
	void test_case_1() { string Arg0 = ">>><<<"; int Arg1 = 6; verify_case(1, Arg1, getLongest(Arg0)); }
	void test_case_2() { string Arg0 = "<<<>>>"; int Arg1 = 0; verify_case(2, Arg1, getLongest(Arg0)); }
	void test_case_3() { string Arg0 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"; int Arg1 = 24; verify_case(3, Arg1, getLongest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MagicalStringDiv1 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 

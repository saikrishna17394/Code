// BEGIN CUT HERE

// END CUT HERE
#line 5 "ForbiddenStrings.cpp"
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

lli dp[31][3][3];

class ForbiddenStrings {
    public:
    long long countNotForbidden(int n) {
         //$CARETPOSITION$
    	if(n==1)
    		return 3;
    	if(n==2)
    		return 9;
    	memset(dp,0,sizeof dp);
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    			dp[2][i][j]=1;

    	lli ans;
    	for(int l=3;l<=n;l++) {
    		ans=0;
    		for(int i=0;i<3;i++) {
    			for(int j=0;j<3;j++) {
    				for(int k=0;k<3;k++) {
    					if(i!=j && j!=k && k!=i)
    						continue;
    					dp[l][i][j]+=dp[l-1][k][i];
    				}
    				ans+=dp[l][i][j];
    				// cout<<dp[l][i][j]<<" "<<l<<" "<<i<<" "<<j<<endl;
    			}
    		}
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 9LL; verify_case(0, Arg1, countNotForbidden(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, countNotForbidden(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 51LL; verify_case(2, Arg1, countNotForbidden(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
     ForbiddenStrings ___test;
      ___test.run_test(-1);
      system("pause");
}
// END CUT HERE 

// BEGIN CUT HERE

// END CUT HERE
#line 5 "Skyscrapers.cpp"
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
int dp[101][101][101];
class Skyscrapers {
    public:
    int solve(int n,int l,int r) {
    	if(n==1) {
    		if(l==1 && r==1)
    			return 1;
    		return 0;
    	}
    	int& ret=dp[n][l][r];
    	if(ret!=-1)
    		return ret;
    	ret=0;
    	if(l)
	    	ret+=solve(n-1,l-1,r);
	    if(r)
	    	ret+=solve(n-1,l,r-1);
	    ret%=mod;

    	lli num=solve(n-1,l,r);
    	num=num*(lli)(n-2);
    	num%=mod;
	    ret+=num;
	    ret%=mod;
	    
	    // cout<<n<<" "<<l<<" "<<r<<" "<<ret<<endl;
	    return ret;
    }
    int buildingCount(int N, int leftSide, int rightSide) {
         //$CARETPOSITION$
    	memset(dp,-1,sizeof dp);
    	return solve(N,leftSide,rightSide);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(0, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 18; verify_case(2, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4872; verify_case(4, Arg3, buildingCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Skyscrapers ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE 
